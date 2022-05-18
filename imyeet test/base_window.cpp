#include "base_window.h"
#include <imyeet.h>
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


bool base_window::create()
{
    bool result = true;
    m_class = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, m_module, NULL, NULL, NULL, NULL, m_classtext.c_str(), NULL };
    ::RegisterClassEx(&m_class);

    m_window = CreateWindow(m_class.lpszClassName, m_windowtext.c_str(), WS_POPUP | WS_SYSMENU | WS_BORDER, 100, 100, 500, 500, NULL, NULL, m_class.hInstance, NULL);
    m_d3dbase = new base_d3d(m_window);

    std::cout << m_window << std::endl;

    if (!m_d3dbase->create_device()) {
        m_d3dbase->cleanup_device();
        result = false;
    }
    else {
        ::ShowWindow(m_window, SW_SHOWDEFAULT);
        ::UpdateWindow(m_window);
    }

    return result;
}

HWND base_window::get_window()
{
    return m_window;
}

base_d3d* base_window::get_d3dbase()
{
    return m_d3dbase;
}

bool is_mouse_down = false;
POINT last_location;
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) {
    case WM_LBUTTONDOWN:
    {
        is_mouse_down = true;
        GetCursorPos(&last_location);
        RECT rect;
        GetWindowRect(hWnd, &rect);
        last_location.x = last_location.x - rect.left;
        last_location.y = last_location.y - rect.top;
        break;
    }
    case WM_LBUTTONUP:
        is_mouse_down = false;
        break;
    case WM_MOUSEMOVE:
    {
        if (is_mouse_down) {
            POINT current_pos;
            GetCursorPos(&current_pos);

            POINT s2c = current_pos;

            ScreenToClient(hWnd, &s2c);

            if (imyeet::in_cursor(s2c, ImVec4(0, 0, 500, 500))) {



                int x = current_pos.x - last_location.x;
                int y = current_pos.y - last_location.y;

                MoveWindow(hWnd, x, y, 500, 500, false);
            }
        }
        break;
    }
    }
    return ::DefWindowProc(hWnd, msg, wParam, lParam);
}