#pragma once
#include "Prerequisites.h"

class DeviceContext {
public:
    DeviceContext() = default;
    ~DeviceContext() { SAFE_RELEASE(m_deviceContext); };

    // Initializes the device context.
    void init();

    // Updates the device context.
    void update();

    // Renders using the device context.
    void render();

    // Destroys the device context.
    void destroy();

    // Clears the depth stencil view.
    void ClearDepthStencilView(ID3D11DepthStencilView* pDepthStencilView,
        unsigned int ClearFlags,
        float Depth,
        unsigned int Stencil);

    // Sets pixel shader resources.
    void PSSetShaderResources(unsigned int StartSlot,
        unsigned int NumViews,
        ID3D11ShaderResourceView* const* ppShaderResourceViews);

public:
    // Pointer to the device context.
    ID3D11DeviceContext* m_deviceContext = nullptr;
};