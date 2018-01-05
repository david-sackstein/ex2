#include "Board.h"

Board::Board()
{
    PieceType layout[8] = {
        PieceType::Castle,
        PieceType::Knight,
        PieceType::Bishop,
        PieceType::King,
        PieceType::Queen,
        PieceType::Bishop,
        PieceType::Knight,
        PieceType::Castle
    };

    for(int i=0; i<8; i++)
    {
        cells[0][i].Color = PlayerColor::Black;
        cells[0][i].Type = layout[i];

        cells[1][i].Color = PlayerColor::Black;
        cells[1][i].Type = PieceType::Pawn;

        cells[6][i].Color = PlayerColor::White;
        cells[6][i].Type = PieceType::Pawn;

        cells[7][i].Color = PlayerColor::White;
        cells[7][i].Type = layout[i];

        for(int j=2; j<6; j++)
        {
            cells[j][i].Color = PlayerColor::White;
            cells[j][i].Type = PieceType::None;
        }
    }
}
