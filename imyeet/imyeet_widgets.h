#pragma once
#include "imyeet.h"











namespace imyeet {

	void begin(std::string m_text, bool d_border, ImU32 border_color, ImVec2 b_size);

	bool checkbox(std::string m_text, bool& is_checked);
	bool button(std::string m_text, ImVec2 m_size, bool b_fillbox = true);

	void begin_child(ImVec2 m_size);

	void fix_padding();

	void end_child();

	void end();
}