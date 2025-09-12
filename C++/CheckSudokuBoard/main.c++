#include <iostream>
#include <vector>

using namespace std;

//bool isCheckedValue(vector<vector<char>>& input, vector<bool>& checked, int i, int j) {
//	int idx = input[i][j] - '0';
//
//	if (input[i][j] == '.')
//		return true;
//	else if (!checked[idx]) {
//		checked[idx] = true;
//		return true;
//	}
//	else
//		return false;
//}
//
//bool boxCheck(vector<vector<char>>& input, int x, int y) {
//	vector<bool> checked(10, false);
//	for (int i = x - 3; i < x; i++)
//		for (int j = y - 3; j < y; j++)
//			if (!isCheckedValue(input, checked, i, j)) return false;
//}
//
//bool fullBoxCheck(vector<vector<char>>& input) {
//	for (int i = 3; i <= 9; i+= 3)
//		for (int j = 3; j <= 9; j+= 3)
//			if (!boxCheck(input, i, j))
//				return false;
//
//	return true;
//}
//
//bool columnCheck(vector<vector<char>>& input) {
//	for (int i = 0; i < 9; i++) {
//		vector<bool> checked(10, false);
//		for (int j = 0; j < 9; j++)
//			if (!isCheckedValue(input, checked, j, i)) return false;
//	}
//	return true;
//}
//
//bool widthCheck(vector<vector<char>>& input) {
//	for (int i = 0; i < 9; i++) {
//		vector<bool> checked(10, false);
//		for (int j = 0; j < 9; j++)
//			if (!isCheckedValue(input, checked, i, j)) return false;
//	}
//	return true;
//}
//
//bool checkSudokuBoard(vector<vector<char>>& input) {
//	if (!widthCheck(input) || !columnCheck(input) || !fullBoxCheck(input)) return false;
//	else return true;
//}

bool isValidRow(vector<vector<char>> & board, int row)
{
	vector<bool> visited(10, false);
	for (auto n : board[row])
	{
		if (n == '.') continue;
		if (visited[n - '0']) return false;
		visited[n - '0'] = true;
	}

	return true;
}

bool isValidColumn(vector<vector<char>>& board, int col)
{
	vector<bool> visited(10, false);
	for (auto r = 0; r < 9; r++) {
		auto c = board[r][col];
		
		if (c == '.') continue;
		if (visited[c - '0']) return false;
		visited[c - '0'] = true;
	}
	return true;
}

bool isValidSubsquare(vector<vector<char>>& board, int pos)
{
	vector<bool> visited(10, false);
	int row = pos / 3 * 3;
	int col = pos % 3 * 3;

	for (int r = row; r < row + 3; r++) {
		for (int c = col; c < col + 3; c++) {
			if (board[r][c] == '.') continue;
			if (visited[board[r][c] - '0']) return false;
			visited[board[r][c] - '0'] = true;
		}
	}

	return true;
}

bool isValidBoard(vector<vector<char>>& board)
{
	for (int i = 0; i < 9; i++) {
		if (!isValidRow(board, i)) return false;
		if (!isValidColumn(board, i)) return false;
		if (!isValidSubsquare(board, i)) return false;
	}

	return true;
}


int main() {
	vector<vector<char>> input1{
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};

	vector<vector<char>> input2{
		{'8','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};

	vector<vector<vector<char>>> data{ input1, input2 };

	for (auto input : data) {
		// cout << boolalpha << checkSudokuBoard(input) << endl;
		cout << boolalpha << isValidBoard(input) << endl;
	}


	return 0;
}