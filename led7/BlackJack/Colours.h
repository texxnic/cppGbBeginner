#pragma once
#include <iostream>
#include <string>

class Colours
{
public:
	enum class Code
	{
		DEFAULT = 0,
		BOLD = 1,
		SEMI_BRIGHT = 2,

		UNDERLINE = 4,
		FLASH = 5,

		REVERSION = 7,

		NORM_INTENSITY = 22,

		UNDO_UNDERLINE = 24,
		UNDO_FLASH = 25,

		UNDO_REVERSION = 27,

		S_BLACK = 30,
		S_RED = 31,
		S_GREEN = 32,
		S_YELLOW = 33,
		S_BLUE = 34,
		S_MAGENTA = 35,
		S_CYAN = 36,
		S_GREY = 37,

		BG_BLACK = 30,
		BG_RED = 41,
		BG_GREEN = 42,
		BG_YELLOW = 43,
		BG_BLUE = 44,
		BG_MAGENTA = 45,
		BG_CYAN = 46,
		BG_GREY = 47,

		BG_DEFAULT = 49,

		S_BRICHT_BLACK = 90,
		S_BRICHT_RED = 91,
		S_BRICHT_GREEN = 92,
		S_BRICHT_YELLOW = 93,
		S_BRICHT_BLUE = 94,
		S_BRICHT_MAGENTA = 95,
		S_BRICHT_CYAN = 96,
		S_BRICHT_GREY = 97,

		BG_BRICHT_BLACK = 100,
		BG_BRICHT_RED = 101,
		BG_BRICHT_GREEN = 102,
		BG_BRICHT_YELLOW = 103,
		BG_BRICHT_BLUE = 104,
		BG_BRICHT_MAGENTA = 105,
		BG_BRICHT_CYAN = 106,
		BG_BRICHT_GREY = 107,
	};

	Colours(Code c_colour);

	friend std::ostream& operator<<(std::ostream& out, const Colours& colour)
	{
		return out << "\033[" << static_cast<int>(colour.code_colour_) << "m";
	}

	int get_code() const;

	~Colours();

private:
	Code code_colour_;

};