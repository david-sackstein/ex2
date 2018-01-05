#include "Console.h"
#include <iostream>

enum Turn
{
	white,
	black,
};

void getPlayersNames(std::string &whitePlayer, std::string &blackPlayer)
{
	std::cout << "Enter white player name:\n";
	getline(std::cin, whitePlayer);

	std::cout << "Enter black player name:\n";
	getline(std::cin, blackPlayer);
}

void getTurn(std::string player, std::string &move)
{
	std::cout<<player<<": Please enter your move:\n";
	getline(std::cin, move);
}

void Run()
{
	Board board;
	Console console;

	std::string whitePlayer;
	std::string blackPlayer;

	getPlayersNames(whitePlayer, blackPlayer);

	while (true)
	{
		Turn turn = white;
		std::string move;

		std::string currPlayer = turn == white ? whitePlayer : blackPlayer;

		getTurn(currPlayer, move);

		turn = turn == white ? black : white;

		break;
	}

	console.PrintBoard(board);
}

int main()
{
	Run();

	return 0;
}