#include <iostream>

#include "Aurora.h"
#include "Board.h"

using namespace std;

int main()
{
    string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    Board board(fen);
    Aurora aurora(fen);

    //board.DrawBoard();

    return 0;
}
