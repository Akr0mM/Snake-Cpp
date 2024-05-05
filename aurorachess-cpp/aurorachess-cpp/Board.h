#pragma once
#include <iostream>
#include<list>

using namespace std;

class Board
{
public:
	Board(string fen);
	
	string fen;
	string boardPosition;

	void DrawBoard(string fenToDraw = "");
};

