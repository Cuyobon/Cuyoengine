#pragma once
#include "Prerequisites.h"
class Device;
class DeviceContext;

class Texture {
public:
    Texture() = default;
    ~Texture();

    // Initializes the texture with a given device and texture name.
    void init(Device device, std::string textureName);

    // Initializes the texture with given dimensions, format, and flags.
    void init(Device device, unsigned width, unsigned height, DXGI_FORMAT Format, unsigned int BlindFlags);

    // Updates the texture.
    void update();

    // Renders the texture.
    void render(DeviceContext& deviceContext, unsigned int StarSlot);

    // Destroys the texture.
    void destroy();

public:
    // The variable is in charge of handling a texture resource as data.
    ID3D11Texture2D* m_texture = nullptr;

    // This variable is in charge of handling a texture resource as image data.
    ID3D11ShaderResourceView* m_textureFromImg;
};