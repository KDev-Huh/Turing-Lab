#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> nums{ 2, 0, 2, 1, 1, 0 };

	int one = 0, two = 0, three = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 0) one++;
		else if (nums[i] == 1) two++;
		else three++;
	}

	for (int i = 0; i < one; i++) {
		cout << 0 << " ";
	}

	for (int i = 0; i < two; i++) {
		cout << 1 << " ";
	}

	for (int i = 0; i < three; i++) {
		cout << 2 << " ";
	}


	return 0;
}