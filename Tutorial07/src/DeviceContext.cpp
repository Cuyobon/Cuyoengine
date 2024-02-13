#include "DeviceContext.h"

void DeviceContext::ClearDepthStencilView(ID3D11DepthStencilView* pDepthStencilView,
    unsigned int ClearFlags,
    float Depth,
    unsigned int Stencil) {
    // Verifica si la vista de profundidad y stencil es v�lida.
    if (pDepthStencilView == nullptr) {
        // Advierte sobre errores en los datos de los par�metros.
        WARNING("ERROR: DeviceContext::ClearDepthStencilView : Error in data from params [CHECK FOR ID3D11DepthStencilView* pDepthStencilView]\n");
        exit(1);
    }
    else {
        // Limpia la vista de profundidad y stencil.
        m_deviceContext->ClearDepthStencilView(pDepthStencilView, ClearFlags, Depth, Stencil);
    }
}

void DeviceContext::PSSetShaderResources(unsigned int StartSlot,
    unsigned int NumViews,
    ID3D11ShaderResourceView* const* ppShaderResourceViews) {
    // Verifica si los recursos de sombreador son v�lidos.
    if (ppShaderResourceViews == nullptr) {
        // Advierte sobre errores en los datos de los par�metros.
        WARNING("ERROR: DeviceContext::ClearDepthStencilView : Error in data from params [CHECK FOR ID3D11ShaderResourceView* const* ppShaderResourceViews]\n");
        exit(1);
    }
    else {
        // Establece recursos de sombreador de p�xeles.
        m_deviceContext->PSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
    }
}
