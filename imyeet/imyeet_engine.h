#pragma once
#include "imyeet_includes.h"













namespace imyeet {
	class imyeet_engine {
	public:

		void add_rect(ImVec4 m_box, ImU32 col, bool is_filled = false, float rounding =  0.0f);
		void add_text(const char* text, ImVec2 pos, ImU32 col);
		ImVec2 m_menupos = ImVec2(0,0);
	};
}