#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int> data) {
	int max = 0;

	for (int i = 0; i < data.size(); i++) {
		int value = data[i] + i;
		
		if (max < i) return false;

		if (max < value)
			max = value;
	}

	return max >= data.size() - 1;
}

bool teacherCanJump(const vector<int>& nums)
{
	int maxJump = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (i > maxJump) return false;
		maxJump = max(maxJump, i + nums[i]);
	}

	return true;
}

bool usaDeveloperCanJump(const vector<int>& nums)
{
	int gas = 0;
	for (auto n : nums) {
		if (gas < 0) return false;
		else if (n > gas) gas = n;
		gas--;
	}

	return true;
}

int main() {
	vector<vector<int>> data{
		{ 2, 3, 1, 1, 4 },
		{3, 2, 1, 0, 4},
		{2, 0, 1, 1, 3},
		{3, 1, 2, 1, 1, 2, 0, 4},
		{4, 1, 1, 1, 0, 2, 1}
	};

	cout << "my results -----------------------------------------------" << endl;

	for (auto v : data) {
		cout << boolalpha << canJump(v) << endl;
	}
	cout << endl;

	cout << "teacher results ------------------------------------------" << endl;

	for (auto v : data) {
		cout << boolalpha << teacherCanJump(v) << endl;
	}
	cout << endl;

	cout << "usa developer results ------------------------------------" << endl;

	for (auto v : data) {
		cout << boolalpha << usaDeveloperCanJump(v) << endl;
	}

	return 0;
}