#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;

class DepthStencilView {
public:
    DepthStencilView() = default;
    ~DepthStencilView() { SAFE_RELEASE(m_depthStencilView); };

    // Initializes the depth stencil view.
    void init(Device device, ID3D11Resource* depthStencil, DXGI_FORMAT format);

    // Updates the depth stencil view.
    void update();

    // Renders using the depth stencil view.
    void render(DeviceContext& deviceContext);

    // Destroys the depth stencil view.
    void destroy();

public:
    // Pointer to the depth stencil view.
    ID3D11DepthStencilView* m_depthStencilView = nullptr;
};