#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> result{ {} };
	int digit = pow(2, nums.size());

	for (int i = 1; i < digit; i++) {
		int idx = 0;
		int elem = i;

		vector<int> ss;
		while (elem > 0) {
			if (elem & 1) ss.emplace_back(nums[idx]);
			idx++;
			elem >>= 1;
		}
		result.emplace_back(ss);
	}

	return result;
}

int main() {
	vector<int> nums{ 1, 2, 3 };

	vector<vector<int>> result = subsets(nums);

	for (auto vector : result) {
		cout << "[";
		for (auto v : vector) {
			cout << v << " ";
		}
		cout << "]" << endl;
	}


	return 0;
}