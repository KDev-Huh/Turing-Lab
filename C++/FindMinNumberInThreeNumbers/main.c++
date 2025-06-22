#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
	int n = 12, l = 3;
	vector<int> nums{ 1, 5, 2, 3, 6, 2, 3, 7, 3, 5, 2, 6 };

	deque<pair<int, int>> dq;

	for (int i = 0; i < n; i++) {
		if (dq.empty()) 
		{
			dq.push_back({ i, nums[i] });
		}
		else
		{
			if (i - dq.front().first >= l)
				dq.pop_front();


			while (!dq.empty() && dq.back().second > nums[i])
				dq.pop_back();

			dq.push_back({ i, nums[i] });
		}

		cout << dq.front().second << " ";
	}

	return 0;
}

//int main() {
//	int n = 12, l = 3;
//	
//	vector<pair<int, int>> result(n + 1, { 5000000, 5000000 });
//
//	vector<int> nums{0, 1, 5, 2, 3, 6, 2, 3, 7, 3, 5, 2, 6 };
//	for (int i = 1; i <= n; i++) {
//		int num = nums[i];
//
//		// 이전 최소 현재것과 확인
//		if (num < result[i - 1].first) {
//			result[i - 1].first = num;
//		}
//		
//		// 현재 최소를 구할때 이전값과 비교
//		if(num > result[i - 1].second)
//		{
//			result[i].first = result[i - 1].second;
//		}
//		else {
//			result[i].first = num;
//		}
//		result[i].second = num;
//	}
//
//	for (int i = 1; i <= n; i++) cout << "(" << result[i].first << ", " << result[i].second << ")" << " ";
//
//
//	return 0;
//}