#include "Texture.h"
#include "Device.h"
#include "DeviceContext.h"

Texture::~Texture()
{
    // Libera la memoria del objeto de textura o de la vista de recursos del sombreador según corresponda.
    if (m_texture != nullptr) {
        SAFE_RELEASE(m_texture);
    }
    else if (m_textureFromImg != nullptr) {
        SAFE_RELEASE(m_textureFromImg);
    }
}

void Texture::init(Device device, std::string textureName)
{
    // Verifica si el dispositivo es válido.
    if (device.m_device == nullptr) {
        // Advierte sobre errores en los datos de los parámetros.
        WARNING("ERROR: Texture::init : Error in data from params [CHECK FOR Device device]\n");
        exit(1);
    }

    // Intenta cargar la textura desde un archivo.
    HRESULT hr = D3DX11CreateShaderResourceViewFromFile(device.m_device,
        textureName.c_str(),
        nullptr,
        nullptr,
        &m_textureFromImg,
        nullptr);
    if (FAILED(hr)) {
        // Advierte sobre errores en los datos de los parámetros o la carga de la textura.
        WARNING("ERROR: Texture::init : Error in data from params [CHECK FOR string textureName -> Verify correct texture name in Filepath]\n");
        exit(1);
    }
}

void Texture::init(Device device,
    unsigned int width,
    unsigned int height,
    DXGI_FORMAT Format,
    unsigned int BindFlags) {
    // Verifica si el dispositivo es válido y los parámetros de tamaño de la textura son válidos.
    if (device.m_device == nullptr) {
        // Advierte sobre errores en los datos de los parámetros.
        WARNING("ERROR: Texture::init : Error in data from params [CHECK FOR Device device]\n");
        exit(1);
    }
    else if (width <= 0 || height <= 0) {
        // Advierte sobre errores en los datos de los parámetros.
        WARNING("ERROR: Texture::init : Error in data from params [CHECK FOR unsigned int width OR unsigned int height, ]\n");
        exit(1);
    }

    HRESULT hr = S_OK;

    // Configura la descripción de la textura 2D.
    D3D11_TEXTURE2D_DESC desc;
    memset(&desc, 0, sizeof(desc));
    desc.Width = width;
    desc.Height = height;
    desc.MipLevels = 1;
    desc.ArraySize = 1;
    desc.Format = Format;
    desc.SampleDesc.Count = 1;
    desc.SampleDesc.Quality = 0;
    desc.Usage = D3D11_USAGE_DEFAULT;
    desc.BindFlags = BindFlags;
    desc.CPUAccessFlags = 0;
    desc.MiscFlags = 0;

    // Crea la textura 2D.
    hr = device.CreateTexture2D(&desc, nullptr, &m_texture);

    if (m_texture == nullptr) {
        // Advierte sobre errores en la creación de la textura.
        WARNING("ERROR: Texture::init : Error in data from params [CHECK FOR m_texture]\n");
        exit(1);
    }
    else if (FAILED(hr)) {
        // Advierte sobre errores en la creación de la textura.
        WARNING("ERROR: Texture::init : Error in data from params [CHECK FOR CreateTexture2D]\n");
        exit(1);
    }
}

void Texture::render(DeviceContext& deviceContext, unsigned int StartSlot) {
    // Renderiza la textura.
    if (m_textureFromImg != nullptr) {
        ID3D11ShaderResourceView* nullSRV[] = { nullptr };
        deviceContext.PSSetShaderResources(StartSlot, 1, nullSRV);
        deviceContext.PSSetShaderResources(StartSlot, 1, &m_textureFromImg);
    }
}

void Texture::destroy() {
    // Libera la memoria del objeto de textura o de la vista de recursos del sombreador según corresponda.
    if (m_texture != nullptr) {
        SAFE_RELEASE(m_texture);
    }
    else if (m_textureFromImg != nullptr) {
        SAFE_RELEASE(m_textureFromImg);
    }
}
