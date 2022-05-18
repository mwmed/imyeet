#include "imyeet_engine.h"

void imyeet::imyeet_engine::add_rect(ImVec4 m_box, ImU32 col, bool is_filled, float rounding)
{
	auto m_drawlist = ImGui::GetForegroundDrawList();

	m_box.x += m_menupos.x;
	m_box.y += m_menupos.y;

	is_filled ? m_drawlist->AddRectFilled(ImVec2(m_box.x, m_box.y), ImVec2(m_box.x + m_box.w, m_box.y + m_box.z), col, rounding) :
		m_drawlist->AddRect(ImVec2(m_box.x, m_box.y), ImVec2(m_box.x + m_box.w, m_box.y + m_box.z), col, rounding);
}

void imyeet::imyeet_engine::add_text(const char* text, ImVec2 pos, ImU32 col)
{
	auto m_drawlist = ImGui::GetForegroundDrawList();

	pos.x += m_menupos.x;
	pos.y += m_menupos.y;

	m_drawlist->AddText(pos, col, text);
}
