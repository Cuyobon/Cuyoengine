#pragma once
#include "Prerequisites.h"


/// <summary>
/// This class is in charge of generatting new window
/// </summary>
class Window
{
public:
    Window();
    ~Window();

    /// <summary>
    /// The method is in charge of generate a window
    /// </summary>
    /// <param name="hInstance"> A single ID for the window / Copy of the resource </param>
    /// <param name="nCmdShow"> Command list window </param>
    /// <param name="wndproc"> Input Bridge </param>
    /// <returns></returns>
    HRESULT
        init(HINSTANCE hInstance, int nCmdShow, WNDPROC wndproc);

    void
        update();

    void
        render();

    void
        destroy();

public:
    HWND m_hWnd = nullptr;
    unsigned int m_width;
    unsigned int m_height;
private:
    HINSTANCE m_hInst = nullptr;
    RECT m_rect;
    std::string m_WindowName = "Direct3D 11 Tutorial 7";
};