#pragma once
#include "imyeet_includes.h"
#include "imyeet_engine.h"
#include "yeet_inputsystem.h"












namespace imyeet {
	void on_create(HWND p_hwnd, LPDIRECT3DDEVICE9 p_device);

	void on_frame_begin();


	void on_draw();

	void on_frame_end();


	bool in_cursor(POINT p, ImVec4 rect);
	bool in_cursor(ImVec4 rect);

	extern imyeet_engine* m_engine;
}