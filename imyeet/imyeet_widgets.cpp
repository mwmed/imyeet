#include "imyeet_widgets.h"


int m_paddingx = 5;
int m_paddingy = 5;

int m_childpaddingx = 15;
int m_childpaddingy = 15;

ImVec2 m_child_size;

ImVec2 m_menusize;
ImVec2 m_menusizecached;


void imyeet::begin(std::string m_text, bool d_border, ImU32 border_color, ImVec2 b_size)
{
	m_menusize = b_size;
	if (d_border) {
		m_engine->add_rect(ImVec4(m_engine->m_menupos.x, m_engine->m_menupos.y, 15, b_size.y),IM_COL32(30,30,30,255), true, 0);
		m_paddingy += 10;
	}

	m_engine->add_rect(ImVec4(m_engine->m_menupos.x, m_engine->m_menupos.y + m_paddingy, b_size.x, b_size.y), border_color, true, 0);

	m_paddingy += 5;


}

bool imyeet::checkbox(std::string m_text, bool& is_checked)
{
	auto m_rect = ImVec4(m_paddingx, m_paddingy,15, 15);
	bool clicked = in_cursor(m_rect) && inputmanager::is_key_up(VK_LBUTTON);
	if (clicked)
		is_checked = !is_checked;

	m_engine->add_rect(m_rect, IM_COL32(55,55,55,255), is_checked, 2);
	m_paddingx += 18;

	m_engine->add_text(m_text.c_str(), ImVec2(m_paddingx, m_paddingy), IM_COL32(255,255,255,255));
	m_paddingx += 50 + m_text.size();
	fix_padding();

	return clicked;
}

bool imyeet::button(std::string m_text, ImVec2 m_size, bool b_fillbox)
{
	auto m_rect = ImVec4(m_paddingx, m_paddingy, m_size.x, m_size.y);
	bool clicked = in_cursor(m_rect) && inputmanager::is_key_up(VK_LBUTTON);
	m_engine->add_rect(m_rect, IM_COL32(55, 55, 55, 255), b_fillbox, 2);
	m_paddingx += 3;
	fix_padding();

	m_engine->add_text(m_text.c_str(), ImVec2(m_paddingx, m_paddingy), IM_COL32(255, 255, 255, 255));


	m_paddingx += m_size.y + 5;
	fix_padding();

	return clicked;
}

void imyeet::begin_child(ImVec2 m_size)
{
	m_childpaddingx = m_paddingx + 3;
	m_childpaddingy = m_paddingy + 5;
	m_child_size = m_size;

	m_engine->add_rect(ImVec4(m_paddingx, m_paddingy, m_size.x, m_size.y), IM_COL32(75,75,75,255), true, 2);
	m_paddingx += 3;
	m_paddingy += 5;

	m_menusizecached = m_menusize;

	m_menusize = m_size;

}

void imyeet::fix_padding()
{
	if (m_menusize.x < m_paddingy) {
		m_paddingx = m_childpaddingx + 5;
		m_paddingy = m_childpaddingy + 10;

	}
}

void imyeet::end_child()
{
	m_paddingx = m_childpaddingx + m_child_size.y + 22;
	m_paddingy = m_childpaddingy + 20;

	m_menusize = m_menusizecached;

	m_childpaddingx = 0;
	m_childpaddingy = 0;

}

void imyeet::end()
{
	m_paddingx = 5;
	m_paddingy = 5;
}
