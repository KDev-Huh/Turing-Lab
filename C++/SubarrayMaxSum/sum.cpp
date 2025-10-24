#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(const vector<int>& nums)
{
	int result = 0, sum = 0;
	for (auto n : nums) {
		sum += n;
		if (sum < 0) sum = 0;
		if (sum > result) result = sum;
	}

	return result;
}

int main()
{
	vector<int> num1{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	vector<int> num2{ 1 };
	vector<int> num3{ 5, 4, -1, 7, 8 };
	vector<vector<int>> nums{ num1, num2, num3 };

	for (auto& num : nums)
		cout << maxSubArray(num) << endl;


	return 0;
}