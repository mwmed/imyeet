#include "imyeet_widgets.h"


int m_paddingx = 5;
int m_paddingy = 5;


void imyeet::begin(std::string m_text, bool d_border, ImU32 border_color, ImVec2 b_size)
{
	if (d_border) {
		m_engine->add_rect(ImVec4(m_engine->m_menupos.x, m_engine->m_menupos.y, 15, b_size.y),IM_COL32(30,30,30,255), true, 0);
		m_paddingy += 10;
	}

	m_engine->add_rect(ImVec4(m_engine->m_menupos.x, m_engine->m_menupos.y + m_paddingy, b_size.x, b_size.y), border_color, true, 0);

	m_paddingy += 5;


}

bool imyeet::checkbox(std::string m_text, bool& is_checked)
{
	auto m_rect = ImVec4(m_paddingx, m_paddingy, 15, 15);
	if (in_cursor(m_rect))
		is_checked = !is_checked;

	m_engine->add_rect(m_rect, IM_COL32(55,55,55,255), is_checked, 2);
	m_paddingx += 18;
	m_engine->add_text(m_text.c_str(), ImVec2(m_paddingx, m_paddingy), IM_COL32(255,255,255,255));
	return false;
}

void imyeet::end()
{
	m_paddingx = 5;
	m_paddingy = 5;
}
