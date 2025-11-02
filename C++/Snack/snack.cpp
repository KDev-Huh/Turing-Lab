//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//bool isCorrectDirection(int d, int x, int y, int limitBottom, int limitTop, int limitRight, int limitLeft, vector<pair<int, int>> direction) {
//	x += direction[d].first;
//	y += direction[d].second;
//
//	return limitLeft <= y and limitRight >= y and limitBottom >= x and limitTop <= x;
//}
//
//vector<vector<int>> snakeVector(vector<vector<int>> data) {
//	vector<pair<int, int>> direction{
//		{0, 1}, {1, 0}, {0, -1}, {-1, 0}
//	};
//	vector<vector<int>> limitPlus{
//		{1, 0, 0, 0},
//		{0, 0, 1, 0},
//		{0, 1, 0, 0},
//		{0, 0, 0, 1}
//	};
//
//	int x = data.size() - 1;
//	int y = data[0].size() - 1;
//
//	int ix = 0,iy = 0, d = 0;
//	int limitBottom = x, limitRight = y, limitTop = 0, limitLeft = 0;
//	vector<vector<int>> results(x + 1, vector<int>(y + 1, 0));
//	for (int i = 0; i <= x; i++) {
//		for (int j = 0; j <= y; j++) {
//			results[ix][iy] = data[i][j];
//
//			if (!isCorrectDirection(d, ix, iy, limitBottom, limitTop, limitRight, limitLeft, direction)) {
//				limitTop += limitPlus[d][0];
//				limitBottom += limitPlus[d][1];
//				limitRight += limitPlus[d][2];
//				limitLeft += limitPlus[d][3];
//				d = (d + 1) % 4;
//			}
//			ix += direction[d].first;
//			iy += direction[d].second;
//		}
//	}
//
//	return results;
//}
//
//int main() {
//	vector<vector<int>> data{
//		{1, 2, 3, 4},
//		{5, 6, 7, 8},
//		{9, 10, 11, 12}
//	};
//
//	vector<vector<int>> results = snakeVector(data);
//
//	for (auto v : results) {
//		for (auto i : v) {
//			cout << i << " ";
//		}
//		cout << endl;
//	}
//
//	return 0;
//}