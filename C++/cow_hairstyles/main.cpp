// 소들의 헤어스타일

#include <iostream>
#include <stack>

//int main() {
//	int n;
//
//	/*std::cin >> n;*/
//	n = 6;
//
//	int h[6] = { 10, 3, 7, 4, 12, 2 };
//
//	std::stack<int> s;
//
//	int total = 0;
//	for (int i = 0; i < n; i++) {
//		while (!s.empty() && h[s.top()] <= h[i]) {
//			total += i - s.top() - 1;
//			s.pop();
//		}
//		s.push(i);
//	}
//
//	while (!s.empty()) {
//		total += n - s.top() - 1;
//		s.pop();
//	}
//
//	std::cout << total;
//
//	return 0;
//}

#include <vector>

using namespace std;

struct COW {
	int pos;
	int height;
};


int main()
{
	int n = 6;
	vector<int> cows{ 10, 3, 7, 4, 12, 2 };
	stack<COW> cst;
	int tot = 0;

	for (int i = 0; i < n; i++) {
		if (cst.empty())
		{
			cst.push({ i, cows[i] });
			continue;
		}

		while (!cst.empty() && cst.top().height <= cows[i])
		{
			tot += i - cst.top().pos - 1;
			cst.pop();
		}
		cst.push({ i, cows[i] });
	}

	while (!cst.empty())
	{
		tot += n - cst.top().pos - 1;
		cst.pop();
	}

	std::cout << tot;
}