#include "base_d3d.h"

bool base_d3d::create_device()
{
    bool result = false;

    if ((m_d3d = Direct3DCreate9(D3D_SDK_VERSION))) {
        ZeroMemory(&m_params, sizeof(m_params));

        m_params.Windowed = TRUE;
        m_params.SwapEffect = D3DSWAPEFFECT_DISCARD;
        m_params.BackBufferFormat = D3DFMT_UNKNOWN;
        m_params.EnableAutoDepthStencil = TRUE;
        m_params.AutoDepthStencilFormat = D3DFMT_D16;
        m_params.PresentationInterval = D3DPRESENT_INTERVAL_ONE; // vsync, use D3DPRESENT_INTERVAL_IMMEDIATE to uncap fps

        if (SUCCEEDED(m_d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_window, D3DCREATE_HARDWARE_VERTEXPROCESSING, &m_params, &m_device)))
            result = true;
    }
    return result;
}

bool base_d3d::cleanup_device()
{
    if (m_d3d) {
        m_d3d->Release();
        m_d3d = 0;
    }

    if (m_device) {
        m_device->Release();
        m_device = 0;
    }
    return false;
}

void base_d3d::reset_device()
{
}

LPDIRECT3DDEVICE9 base_d3d::get_device()
{
    return m_device;
}
