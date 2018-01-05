#pragma once

#include "Board.h"
#include "UnicodeBuilder.h"

class Console
{
public:

    Console();

    void ClearScreen();
    void PrintBoard(const Board &board);

private:

    void PrintLetterLine();
    void PrintCells(const Board &board, int row);

    void Print(Foreground f, Background b, PlayerColor playerColor, PieceType pieceType);
    void Print(Foreground f, Background b, const std::string& text);
    void PrintLine();
    void PrintSpace();

    UnicodeBuilder _unicodeBuilder;
};
