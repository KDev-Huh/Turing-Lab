#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

struct  Point {
	int row;
	int col;
};

using namespace std;

int removeCells(vector<string>& cplx, int ro, int co) {

	const vector<Point> move{ {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	stack<Point> dst;
	cplx[ro][co] = 0;
	dst.push({ ro, co });
	int cnt = 1;

	while (!dst.empty())
	{
		auto [t, c] = dst.top();
		dst.pop();
		
		for (auto& [mr, mc] : move)
		{
			int tr = t + mr;
			int tc = c + mc;

			if (tr >= 0 and tr < cplx.size() and
				tc >= 0 and tr < cplx.size() and
				cplx[tr][tc] == '1')
			{
				cplx[tr][tc] = '0';
				dst.push({ tr, tc });
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {
	vector<string> cplx{
		"0110100",
		"0110101",
		"1110101",
		"0000111",
		"0100000",
		"0111110",
		"0111000"
	};

	vector<int> num;

	for (int r = 0; r < cplx.size(); r++)
		for (int c = 0; c < cplx.size(); c++)
			if(cplx[r][c] == '1')
				num.push_back(removeCells(cplx, r, c));

	sort(num.begin(), num.end());
	cout << num.size() << endl;
	for (auto n : num)
		cout << n << endl;

	return 0;
}