#include "Aurora.h"

Aurora::Aurora(string fen) : fen(fen) {
	Load(fen);
}

void Aurora::Load(string fen) {
	cout << "Loading " << fen << endl;

	size_t space = fen.find(' ');
	string fenBoard = fen.substr(0, space);

	unordered_map<char, string> bitboardsChar = {
		{'P', "wp"}, {'R', "wr"}, {'B', "wb"}, {'N', "wn"}, {'Q', "wq"}, {'K', "wk"},
		{'p', "bp"}, {'r', "br"}, {'n', "bn"}, {'b', "bb"}, {'q', "bq"}, {'k', "bk"}
	};

	unordered_map<string, string> bitboards;
	for (const auto& entry : bitboardsChar) {
		bitboards[entry.second] = "";
	}

	for (char c : fenBoard) {
		if (c != '/') {
			if (isdigit(c)) {
				for (int i = 0; i < (c - '0'); ++i) {
					for (auto& entry : bitboards) {
						entry.second += '0';
					}
				}
			}
			else {
				auto it = bitboardsChar.find(c);
				if (it != bitboardsChar.end()) {
					for (auto& entry : bitboards) {
						if (entry.first == it->second) {
							entry.second += '1';
						}
						else {
							entry.second += '0';
						}
					}
				}
			}
		}
	}

	cout << bitboards["br"] << endl;

	wp = stoll(bitboards["wp"], nullptr, 2);
	wr = stoll(bitboards["wr"], nullptr, 2);
	wn = stoll(bitboards["wn"], nullptr, 2);
	wb = stoll(bitboards["wb"], nullptr, 2);
	wq = stoll(bitboards["wq"], nullptr, 2);
	wk = stoll(bitboards["wk"], nullptr, 2);
	bp = stoll(bitboards["bp"], nullptr, 2);
	//br = stoll("1000000100000000000000000000000000000000000000000000000000000000", nullptr, 2); trop grand est bug 
	//bn = stoll(bitboards["bn"], nullptr, 2);
	//bb = stoll(bitboards["bb"], nullptr, 2);
	//bq = stoll(bitboards["bq"], nullptr, 2);
	//bk = stoll(bitboards["bk"], nullptr, 2);

	cout << wp << endl;
	cout << wr << endl;
	cout << wn << endl;
	cout << wb << endl;
	cout << wq << endl;
	cout << wk << endl;
	cout << bp << endl;
	cout << br << endl;
	cout << bn << endl;
	cout << bb << endl;
	cout << bq << endl;
	cout << bk << endl;
}
