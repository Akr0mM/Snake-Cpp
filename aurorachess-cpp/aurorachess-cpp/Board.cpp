#include "Board.h"

Board::Board(string fen) : fen(fen) {
	size_t space = fen.find(' ');
	boardPosition = fen.substr(0, space);
};

void Board::DrawBoard(string fenToDraw) {
	if (fenToDraw.empty()) {
		fenToDraw = fen;
	}

	cout << "Fen : " << fenToDraw << endl << "Position : " << endl << "  +---+---+---+---+---+---+---+---+" << endl;

	size_t space = fenToDraw.find(' ');
	boardPosition = fenToDraw.substr(0, space);

	size_t pos = 0;
	int rowNumber = 8;
	while (pos < boardPosition.length()) {
		size_t slashPos = boardPosition.find("/", pos);
			
		string row;
		if (slashPos == string::npos) {
			row = boardPosition.substr(pos);
		}
		else {
			row = boardPosition.substr(pos, slashPos - pos);
			pos = slashPos;
		}

		cout << rowNumber-- << " | ";

		for (char piece : row) {
			if (isdigit(piece)) {
				int num_empty = piece - '0';
				for (int i = 0; i < num_empty; ++i) {
					cout << "  | ";
				}
			}
			else {
				cout << piece << " | ";
			}
		}
		cout << endl << "  +---+---+---+---+---+---+---+---+" << endl;

		pos = slashPos == string::npos ? string::npos : slashPos + 1;
	}

	cout << "    a   b   c   d   e   f   g   h  " << endl << endl;
}