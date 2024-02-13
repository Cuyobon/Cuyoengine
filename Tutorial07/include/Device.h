#pragma once
#include "Prerequisites.h"

class Device {
public:
    Device() = default;
    ~Device() = default;

    // Initializes the device.
    void init();

    // Updates the device.
    void update();

    // Renders using the device.
    void render();

    // Destroys the device.
    void destroy();

    // Creates a render target view.
    HRESULT CreateRenderTargetView(ID3D11Resource* pResource,
        const D3D11_RENDER_TARGET_VIEW_DESC* pDesc,
        ID3D11RenderTargetView** ppRTView);

    // Creates a 2D texture.
    HRESULT CreateTexture2D(const D3D11_TEXTURE2D_DESC* pDesc,
        const D3D11_SUBRESOURCE_DATA* pInitialData,
        ID3D11Texture2D** ppTexture2D);

    // Creates a depth stencil view.
    HRESULT CreateDepthStencilView(ID3D11Resource* pResource,
        const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc,
        ID3D11DepthStencilView** ppDepthStencilView);

public:
    // Pointer to the device.
    ID3D11Device* m_device = nullptr;
};