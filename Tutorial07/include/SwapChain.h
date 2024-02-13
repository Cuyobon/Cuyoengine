#pragma once
#include "Prerequisites.h"
class Device;
class DeviceContext;
class Window;
class Texture;

class SwapChain {
public:
    SwapChain() = default;
    ~SwapChain() { SAFE_RELEASE(m_swapChain); };

    // Initializes the swap chain with the given device, device context, back buffer texture, and window.
    void init(Device& device, DeviceContext& deviceContext, Texture& backBuffer, Window window);

    // Updates the swap chain.
    void update();

    // Renders the swap chain.
    void render();

    // Destroys the swap chain.
    void destroy();

public:
    // Pointer to the swap chain object.
    IDXGISwapChain* m_swapChain = nullptr;

private:
    // The driver type.
    D3D_DRIVER_TYPE m_driverType = D3D_DRIVER_TYPE_NULL;

    // The feature level.
    D3D_FEATURE_LEVEL m_feature_level = D3D_FEATURE_LEVEL_11_0;
};