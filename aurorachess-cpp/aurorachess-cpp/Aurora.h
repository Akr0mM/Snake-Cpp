#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include<list>

using namespace std;

class Aurora
{
public:
	Aurora(string fen);
	void Load(string fen);
	string fen;

	long long wp = 0;
	long long wr = 0;
	long long wn = 0;
	long long wb = 0;
	long long wq = 0;
	long long wk = 0;
	long long bp = 0;
	long long br = 0;
	long long bn = 0;
	long long bb = 0;
	long long bq = 0;
	long long bk = 0;
};

