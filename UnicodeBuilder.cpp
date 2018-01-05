#include "UnicodeBuilder.h"
#include <sstream>

// http://jkorpela.fi/chars/spaces.html
//https://en.wikipedia.org/wiki/Halfwidth_and_fullwidth_forms

std::string UnicodeBuilder::GetClearScreen()
{
	return "\33[2J";
}

std::string UnicodeBuilder::GetPiece(PlayerColor color, PieceType type)
{
	switch(type)
	{
		case PieceType::King:      return color == PlayerColor::White ? "\u2654" : "\u265A";
		case PieceType::Queen:     return color == PlayerColor::White ? "\u2655" : "\u265B";
		case PieceType::Castle:    return color == PlayerColor::White ? "\u2656" : "\u265C";
		case PieceType::Bishop:    return color == PlayerColor::White ? "\u2657" : "\u265D";
		case PieceType::Knight:    return color == PlayerColor::White ? "\u2658" : "\u265E";
		case PieceType::Pawn:      return color == PlayerColor::White ? "\u2659" : "\u265F";
		case PieceType::None:      return GetSpace();
	}
	return "Unknown";
}

std::string UnicodeBuilder::GetColor(Foreground f, Background b)
{
	std::stringstream ss;

	ss << "\33[";
	ss << (int)f;
	ss << ";";
	ss << (int)b;
	ss << "m";

	return ss.str();
}

std::string UnicodeBuilder::GetResetColor()
{
	return "\33[0m";
}

std::string UnicodeBuilder::GetSpace()
{
    return "\u3000";
}

std::string UnicodeBuilder::GetLetter(char c)
{
    if (c < 'A' || c > 'H')
    {
        return "?";
    }

    const char* letters[8] = {
        "\uFF21",
        "\uFF22",
        "\uFF23",
        "\uFF24",
        "\uFF25",
        "\uFF26",
        "\uFF27",
        "\uFF28"
    };

    return letters[c - 'A'];
}

std::string UnicodeBuilder::GetDigit(int digit)
{
    if (digit < 0 || digit > 9)
    {
        return "?";
    }

    const char* digits[8] = {
            "\uFF10",
            "\uFF11",
            "\uFF12",
            "\uFF13",
            "\uFF14",
            "\uFF15",
            "\uFF16",
            "\uFF17"
    };

    return digits[digit];
}
