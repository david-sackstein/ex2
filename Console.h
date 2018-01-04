#pragma once

#include "Enums.h"
#include "UnicodeBuilder.h"
#include <string>

class Console
{
public:

    Console();

    void ClearScreen();

    void Print(Foreground f, Background b, PlayerColor playerColor, PieceType pieceType);
    void Print(Foreground f, Background b, const std::string& text);
    void PrintLine(Foreground f, Background b, const std::string& text);

private:

    UnicodeBuilder _unicodeBuilder;
};
