#include "DepthStencilView.h"
#include "Device.h"
#include "DeviceContext.h"

void DepthStencilView::init(Device device, ID3D11Resource* depthStencil, DXGI_FORMAT format) {
    // Verifica si el dispositivo es válido.
    if (device.m_device == nullptr) {
        WARNING("ERROR: Device::DepthStencilView::init : Error in data from params [CHECK FOR Device device]\n");
        exit(1);
    }
    // Verifica si el recurso de stencil es válido.
    else if (depthStencil == nullptr) {
        WARNING("ERROR: Device::DepthStencilView::init : Error in data from params [CHECK FOR ID3D11Resource* depthStencil]\n");
        exit(1);
    }
    else {
        // Configura la descripción de la vista de stencil.
        D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
        memset(&descDSV, 0, sizeof(descDSV));
        descDSV.Format = format;
        descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
        descDSV.Texture2D.MipSlice = 0;

        // Crea la vista de stencil.
        device.CreateDepthStencilView(depthStencil, &descDSV, &m_depthStencilView);
    }
}

void DepthStencilView::update() {
    // Actualiza la vista de stencil.
}

void DepthStencilView::render(DeviceContext& deviceContext){
    // Limpia la vista de stencil.
    deviceContext.ClearDepthStencilView(m_depthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
}

void DepthStencilView::destroy() {
    // Libera la memoria de la vista de stencil.
    SAFE_RELEASE(m_depthStencilView);
}
