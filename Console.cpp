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

void Console::PrintBoard(const Board &board)
{
	PrintLetterLine();

	for (int row = 0; row < 8; row++)
	{
		std::string digit = _unicodeBuilder.GetDigit(row);

		Print(Foreground::White, Background::Blue, digit);
		PrintSpace();

		PrintCells(board, row);

		PrintSpace();
		Print(Foreground::White, Background::Blue, digit);

		PrintLine();
	}

	PrintLine();
	PrintLetterLine();
}

void Console::PrintLetterLine()
{
	PrintSpace();
	PrintSpace();

	for (char col = 'A'; col < 'I'; col++)
	{
		std::string letter = _unicodeBuilder.GetLetter(col);

		Print(Foreground::White, Background::Blue, letter);
	}

	PrintLine();
	PrintLine();
}

void Console::PrintCells(const Board &board, int row)
{
	for (int col = 0; col < 8; col++)
	{
		const auto &cell = board.cells[row][col];

		bool isBlue = (col + row) % 2 == 0;
		Background b = isBlue ? Background::Blue : Background::Green;

		Print(Foreground::Black, b, cell.Color, cell.Type);
	}
}

void Console::Print(Foreground f, Background b, PlayerColor playerColor, PieceType pieceType)
{
	Print(f, b, _unicodeBuilder.GetPiece(playerColor, pieceType));
}

void Console::Print(Foreground f, Background b, const std::string &text)
{
	std::string colorString = _unicodeBuilder.GetColor(f, b);
	std::string resetString = _unicodeBuilder.GetResetColor();

	std::cout << colorString << text << resetString;
}

void Console::PrintLine()
{
	std::cout << std::endl;
}

void Console::PrintSpace()
{
	std::cout << _unicodeBuilder.GetSpace();
}


