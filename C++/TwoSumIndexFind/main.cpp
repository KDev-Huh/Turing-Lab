#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//vector<int> findTwoSum(vector<int>& nums, int target)
//{
//	int size = nums.size();
//	vector<pair<int, int>> pnum(size);
//	vector<int> result;
//
//	for (int i = 0; i < size; i++) {
//		pnum[i] = { nums[i], i };
//	}
//
//	sort(pnum.begin(), pnum.end());
//
//	int left = 0, right = size - 1;
//	while (left < right) {
//		int sum = pnum[left].first + pnum[right].first;
//		if (sum == target) {
//			result.push_back(pnum[left].second);
//			result.push_back(pnum[right].second);
//			return result;
//		}
//		else if (sum < target) left++;
//		else right--;
//	}
//
//	return {  };
//}

vector<int> findTwoSum(vector<int>& nums, int target) {


	int size = nums.size();
	unordered_map<int, int> hash;

	for (int i = 0; i < size; i++) {
		int complement = target - nums[i];

		if (hash.find(complement) != hash.end())
		{
			return { hash[complement], i };
		}

		hash[nums[i]] = i;
	}

	return {};
}

int main() {
	vector<int> nums{
		4, 9, 8, 7, 2, 5, 3
	};

	vector<int> result = findTwoSum(nums, 9);

	if (!result.size()) {
		cout << "답을 찾을 수 없습니다....";
	}
	else {
		cout << result[0] << " " << result[1];
	}

	return 0;
}