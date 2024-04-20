#include "Window.h"

Window::Window()
{
    // Constructor por defecto
}

Window::~Window()
{
    // Destructor
}

HRESULT Window::init(HINSTANCE hInstance, int nCmdShow, WNDPROC wndproc)
{
    // Inicializa la ventana

    // Almacena el handle de la instancia de la aplicación
    m_hInst = hInstance;

    // Registra la clase de la ventana
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

    // Crea la ventana
    RECT rc = { 0, 0, 1920, 1080 };
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

    // Muestra la ventana
    ShowWindow(m_hWnd, nCmdShow);

    // Obtiene las dimensiones de la ventana
    GetClientRect(m_hWnd, &m_rect);
    m_width = m_rect.right - m_rect.left;
    m_height = m_rect.bottom - m_rect.top;

    return S_OK;
}

void Window::update()
{
    // Actualiza la ventana
}

void Window::render()
{
    // Renderiza la ventana
}

void Window::destroy()
{
    // Destruye la ventana
}
