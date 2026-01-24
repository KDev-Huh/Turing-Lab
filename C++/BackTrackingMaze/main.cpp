#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<pair<int, int>> direction{ {1, 0}, {-1, 0}, { 0, -1 }, {0, 1} };

bool nextCanGo(const vector<vector<char>>& board, vector<vector<bool>> history, string word, int idx, pair<int, int> before) {
	cout << before.first << " " << before.second << endl;
	if (word.size() == idx) return true;

	int maxX = board.size(), maxY = board[0].size();

	for(auto d : direction) {
		int x = before.first + d.first;
		int y = before.second + d.second;

		if (!(x > -1 and x < maxX and y > -1 and y < maxY)) continue;

		if (board[x][y] == word[idx] and history[x][y] == false) {
			history[x][y] = true;
			if (nextCanGo(board, history, word, idx + 1, { x, y })) return true;
			else {
				history[x][y] = false;
			}
		}
	}
	return false;
}

bool exit(const vector<vector<char>>& board, string word) {
	vector<vector<bool>> history(board.size(), vector<bool>(board[0].size(), false));

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] == word[0]) {
				history[i][j] = true;
				if (nextCanGo(board, history, word, 1, {i, j})) {
					return true;
				}
			}
		}
	}

	return false;
}

using V1C = vector<char>;
using V2C = vector<V1C>;
using V1S = vector<string>;

const vector<pair<int, int>> dir{ {-1, 0}, {0, 1}, {1, 0}, {-1, 0} };

bool match(V2C& board, string& word, int row, int col, int matched) 
{
	if (matched == word.size()) return true;

	// boundry check
	if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()
		|| board[row][col] != word[matched])
		return false;

	char tmp = board[row][col];
	board[row][col] = '#';

	bool found = false;

	for (auto [r, c] : dir) {
		found = found || match(board, word, row + r, col + c, matched + 1);
	}

	board[row][col] = tmp;

	return found;
}

bool teacherExist(vector<vector<char>>& board, string word) 
{
	int row = board.size();
	int col = board[0].size();

	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; c++)
			if (match(board, word, r, c, 0))
				return true;
}

int main() {
	vector<vector<char>> board{
		{'a', 'b', 'c', 'e'},
		{'s', 'f', 'c', 's'},
		{'a', 'd', 'e', 'e'}
	};

	string word = "asad";

	cout << boolalpha << teacherExist(board, word);

	return 0;
}