#pragma once

enum class Background
{
    Red = 41,
    Green = 42,
    Blue = 46
};

enum class Foreground
{
    Black = 30,
    White = 37
};

enum class PlayerColor
{
    Black,
    White
};

enum class PieceType
{
    None,
    King,
    Queen,
    Castle,
    Bishop,
    Knight,
    Pawn
};

class Piece
{
public:
    PieceType Type;
    PlayerColor Color;
};