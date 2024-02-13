#include "Device.h"

void Device::init()
{
    // Inicializa el dispositivo.
}

void Device::update()
{
    // Actualiza el dispositivo.
}

void Device::render() {
    // Renderiza con el dispositivo.
}

void Device::destroy() {
    // Libera la memoria del dispositivo.
    SAFE_RELEASE(m_device);
}

HRESULT Device::CreateRenderTargetView(ID3D11Resource* pResource,
    const D3D11_RENDER_TARGET_VIEW_DESC* pDesc,
    ID3D11RenderTargetView** ppRTView) {
    HRESULT hr = S_OK;
    // Verifica si el recurso y la vista de render target existen.
    if (pResource != nullptr || ppRTView != nullptr) {
        // Crea la vista de render target.
        hr = m_device->CreateRenderTargetView(pResource, pDesc, ppRTView);
        WARNING("Device::CreateRenderTargetView : [CREATION OF RESOURCE : OK] \n");
    }
    else {
        // Advierte sobre errores en los datos de los parámetros.
        WARNING("Device::CreateRenderTargetView : Error in data from params [CHECK FOR CREATION METHOD] : OK \n");
        exit(1);
    }
    return hr;
}

HRESULT Device::CreateTexture2D(const D3D11_TEXTURE2D_DESC* pDesc,
    const D3D11_SUBRESOURCE_DATA* pInitialData,
    ID3D11Texture2D** ppTexture2D) {
    HRESULT hr = S_OK;
    // Verifica si el descriptor de la textura y la textura existen.
    if (pDesc != nullptr || ppTexture2D != nullptr) {
        // Crea la textura 2D.
        hr = m_device->CreateTexture2D(pDesc, pInitialData, ppTexture2D);
        WARNING("Device::CreateRenderTargetView : [CREATION OF RESOURCE : OK] \n");
    }
    else {
        // Advierte sobre errores en los datos de los parámetros.
        WARNING("Device::CreateRenderTargetView : Error in data from params [CHECK FOR CREATION METHOD] : OK \n");
        exit(1);
    }
    return hr;
}

HRESULT Device::CreateDepthStencilView(ID3D11Resource* pResource,
    const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc,
    ID3D11DepthStencilView** ppDepthStencilView) {
    HRESULT hr = S_OK;
    // Verifica si el recurso y la vista de stencil existen.
    if (pResource == nullptr) {
        // Advierte sobre errores en los datos de los parámetros.
        WARNING("Device::CreateDepthStencilView : Error in data from params [CHECK FOR ID3D11Resource* pResource] \n");
        exit(1);
    }
    else if (ppDepthStencilView == nullptr) {
        // Advierte sobre errores en los datos de los parámetros.
        WARNING("Device::CreateDepthStencilView : Error in data from params [CHECK FOR ID3D11DepthStencilView** ppDepthStencilView] \n");
        exit(1);
    }
    else {
        // Crea la vista de stencil.
        hr = m_device->CreateDepthStencilView(pResource, pDesc, ppDepthStencilView);
        WARNING("Device::CreateDepthStencilView : [CREATION OF RESOURCE : OK] \n");
    }
    return hr;
}
