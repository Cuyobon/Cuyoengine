#pragma once
#include "Prerequisites.h"

/// <summary>
/// This class is in charge of generating new windows.
/// </summary>
class Window {
public:
    Window();
    ~Window();

    /// <summary>
    /// The method is in charge of generating a window.
    /// </summary>
    /// <param name="hInstance">A single ID for the window / Copy of the resource</param>
    /// <param name="nCmdShow">Command list window</param>
    /// <param name="wndproc">Input Bridge</param>
    /// <returns></returns>
    HRESULT init(HINSTANCE hInstance, int nCmdShow, WNDPROC wndproc);

    void update();

    void render();

    void destroy();

public:
    // This variable holds the window handle.
    HWND m_hWnd = nullptr;

    // The width of the window.
    unsigned int m_width;

    // The height of the window.
    unsigned int m_height;

private:
    // Handle to the instance.
    HINSTANCE m_hInst = nullptr;

    // The window's rectangle.
    RECT m_rect;

    // The name of the window.
    std::string m_WindowName = "Direct3D 11 Tutorial 7";
};