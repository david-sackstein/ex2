#include "Console.h"
#include <windows.h>
#include <iostream>

Console::Console()
{
    SetConsoleOutputCP(437);
}

void Console::ClearScreen()
{
    std::cout << _unicodeBuilder.GetClearScreen();
}

void Console::Print(Foreground f, Background b, PlayerColor playerColor, PieceType pieceType)
{
    PrintLine(f, b, _unicodeBuilder.GetPiece(playerColor, pieceType));
}

void Console::Print(Foreground f, Background b, const std::string& text)
{
    std::string colorString = _unicodeBuilder.GetColor(f, b);
    std::string resetString = _unicodeBuilder.GetResetColor();

    std::cout << colorString << text << resetString;
}

void Console::PrintLine(Foreground f, Background b, const std::string& text)
{
    Print(f, b, text);
    std::cout << std::endl;
}
