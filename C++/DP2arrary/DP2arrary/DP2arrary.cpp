#include <iostream>

int hap(int x1, int y1, int x2, int y2, int (* board)[6]) {
	return board[x2][y2] - board[x2][y1 - 1] - board[x1 - 1][y2] + board[x1 - 1][y1 - 1];
}


int main() {
	int board[5][5] = { {1, 2, 3, 4, 5},
						{6, 7, 8, 9, 10},
						{11, 12, 13, 14, 15},
						{16, 17, 18, 19, 20},
						{21, 22, 23, 24, 25} };

	int result[6][6] = { 0 };

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			result[i][j] = result[i - 1][j] + result[i][j - 1] + board[i - 1][j - 1] - result[i-1][j-1];
		}
	}

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			std::cout << result[i][j] << " " ;
		}
		std::cout << std::endl;
	}

	int x1, y1, x2, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;

	std::cout << hap(x1, y1, x2, y2, result);


	return 0;
}