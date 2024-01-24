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
[12:26 AM]
------------------------------------------------ -
[12:26 AM]
#include "Window.h"

Window::Window()
{
}

Window::~Window()
{
}

HRESULT Window::init(HINSTANCE hInstance, int nCmdShow, WNDPROC wndproc)
{
    m_hInst = hInstance;
    // Register class
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = wndproc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = m_hInst;
    wcex.hIcon = LoadIcon(m_hInst, (LPCTSTR)IDI_TUTORIAL1);
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = "TutorialWindowClass";
    wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_TUTORIAL1);
    if (!RegisterClassEx(&wcex))
        return E_FAIL;

    // Create window
    RECT rc = { 0, 0, 640, 480 };
    m_rect = rc;
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
    m_hWnd = CreateWindow("TutorialWindowClass",
        "Direct3D 11 Tutorial 7",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        m_rect.right - m_rect.left,
        m_rect.bottom - m_rect.top,
        nullptr,
        nullptr,
        m_hInst,
        nullptr);
    if (!m_hWnd)
        return E_FAIL;

    ShowWindow(m_hWnd, nCmdShow);

    GetClientRect(m_hWnd, &m_rect);
    m_width = m_rect.right - m_rect.left;
    m_height = m_rect.bottom - m_rect.top;

    return S_OK;
}

void
Window::update()
{
}

void
Window::render()
{
}

void
Window::destroy()
{
}

