#include "imyeet.h"













namespace imyeet {
	imyeet_engine* m_engine = nullptr;
	HWND m_hwnd = 0;
	POINT mouse_pos;
	void on_create(HWND p_hwnd, LPDIRECT3DDEVICE9 p_device) {
		m_hwnd = p_hwnd;
		ImGui::CreateContext();
		ImGui_ImplWin32_Init(p_hwnd);
		ImGui_ImplDX9_Init(p_device);
		m_engine = new imyeet_engine();
	}
	void on_frame_begin()
	{
		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		GetCursorPos(&mouse_pos);
		ScreenToClient(m_hwnd,&mouse_pos);

		inputmanager::on_update();
	}
	void on_draw()
	{
	}
	void on_frame_end()
	{
		ImGui::EndFrame();
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
	}
	bool in_cursor(POINT p, ImVec4 rect)
	{
		return (p.x >= rect.x && p.x <= rect.x + rect.w && p.y >= rect.y && p.y <= rect.y + rect.z);
	}
	bool in_cursor(ImVec4 rect)
	{
		return (mouse_pos.x >= rect.x && mouse_pos.x <= rect.x + rect.w && mouse_pos.y >= rect.y && mouse_pos.y <= rect.y + rect.z);

	}
}