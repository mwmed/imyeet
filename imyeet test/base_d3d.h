#pragma once
#include "yeet_includes.h"














class base_d3d {
public:
	inline base_d3d(HWND d_window) : m_window(d_window) {}


	bool create_device();
	bool cleanup_device();

	void reset_device();

	LPDIRECT3DDEVICE9 get_device();

private:
	LPDIRECT3D9 m_d3d = 0;
	LPDIRECT3DDEVICE9 m_device = 0;
	D3DPRESENT_PARAMETERS m_params = {};

private:
	HWND m_window = 0;
};