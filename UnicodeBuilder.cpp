#include "UnicodeBuilder.h"
#include <sstream>

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
        case PieceType::None:      return "  ";
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
