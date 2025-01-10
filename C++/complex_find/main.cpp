//#include <iostream>
//#include <string>
//#include <vector>
//
//bool isNear(std::vector<std::vector<int>> map, int x, int y, int idx) {
//	if (x > 0) {
//		if (map[x - 1][y] == idx) {
//			return true;
//		}
//	}
//	if (x < 6) {
//		if (map[x + 1][y] == idx) {
//			return true;
//		}
//	}
//	if (y > 0) {
//		if (map[x][y - 1] == idx) {
//			return true;
//		}
//	}
//	if (y < 6) {
//		if (map[x][y + 1] == idx) {
//			return true;
//		}
//	}
//	
//	return false;
//}
//
//struct  Point {
//	int row;
//	int col;
//};
//
//int main() {
//	std::vector<std::string> cplx{
//		"0110100",
//		"0110101",
//		"1110101",
//		"0000111",
//		"0100000",
//		"0111110",
//		"0111000"
//	};
//
//	std::vector<std::vector<int>> map;
//
//	int f = 0;
//	for (int i = 0; i < 7; i++) {
//		for (int j = 0; j < 7; j++) {
//			if (!f && cplx[i][j] == 1) {
//				map[i][j] = 2;
//				f = 1;
//				continue;
//			}
//			map[i][j] = cplx[i][j];
//		}
//	}
//
//	int idx = 2;
//	for (int i = 0; i < 7; i++) {
//		for (int j = 0; j < 7; j++) {
//			if (map[i][j] == 1) {
//				if (isNear(map, i, j, idx)) {
//					map[i][j] = idx;
//				}
//				else {
//					map[i][j] = ++idx;
//				}
//			}
//		}
//	}
//
//	std::vector<int> count(idx, 0);
//	for (int i = 0; i < map.size(); i++) {
//		for (int j = 0; j < map.size(); j++) {
//			count[map[i][j]-1] += 1;
//		}
//	}
//
//	std::cout << idx - 1;
//
//	for (int i = 0; i < count.size(); i++) {
//		std::cout << count[i] << " " << i;
//	}
//
//
//
//	return 0;
//}