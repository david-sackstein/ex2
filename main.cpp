#include "Console.h"

void Run(Foreground f, Background b)
{
    Console console;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {

            PlayerColor color = (PlayerColor) (i);
            PieceType type = (PieceType) (j);

            console.Print(f, b, color, type);
        }
    }
}

int main() {

    Run (Foreground::Black, Background::Red);

    return 0;
}