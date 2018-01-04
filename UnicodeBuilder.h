#pragma once

#include "Enums.h"
#include <string>

class UnicodeBuilder
{
public:

    std::string GetClearScreen();
    std::string GetPiece(PlayerColor color, PieceType type);
    std::string GetColor(Foreground f, Background b);
    std::string GetResetColor();
};

