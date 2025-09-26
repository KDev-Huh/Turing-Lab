#include <iostream>
#include <vector>

using namespace std;

//int maxJumpIdx(int idx, vector<int>& nums, int size) {
//	int maxJump = nums[idx];
//
//	int maxIdx = idx + 1;
//	for (int i = idx + 2; i <= idx + maxJump && i < size; i++) {
//		if (nums[maxIdx] + maxIdx < nums[i] + i) {
//			maxIdx = i;
//		}
//	}
//
//	return maxIdx;
//}
//
//int countJump(vector<int>& nums) {
//	int size = nums.size();
//
//	if (size == 1) return 0;
//
//	int idx = 0, count = 0;
//	while ((idx + 1) + nums[idx] < size) {
//		idx = maxJumpIdx(idx, nums, size);
//		count++;
//	}
//	count++;
//
//	return count;
//}

int jump(vector<int>& nums)
{
	int jump = 0, curEnd = 0, curFarthest = 0;

	for (int i = 0; i < nums.size() - 1; i++) {
		curFarthest = max(curFarthest, i + nums[i]);

		if (i == curEnd) {
			jump++;
			curEnd = curFarthest;
		}
	}

	return jump;
}

int main() {
	vector<vector<int>> nums{
		{3},
		{2, 3, 1, 1, 4},
		{2, 3, 0, 1, 4},
		{ 3, 4, 3, 2, 5, 4, 3 },
		{1, 4}
	}; // 3

	for (auto values : nums) {
		cout << jump(values) << endl;
	}

	return 0;
}