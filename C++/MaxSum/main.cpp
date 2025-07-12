#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;

	/*cin >> n;

	int num;
	vector<int> numbers(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}*/

	vector<int> numbers { -9, 3, 0, -1, 5, -3, 4, 7, 1, 0, 1 };

	bool zero = 0;
	int one = 0;
	vector<int> up;
	vector<int> down;
	for (auto v : numbers) {
		if (v == 1) one++;
		else if (v > 0) up.push_back(v);
		else if (v < 0) down.push_back(v);
		else if (v == 0) zero = 1;
	}

	sort(up.begin(), up.end());

	vector<int> result;
	reverse(up.begin(), up.end());
	if (up.size() % 2 != 0) {
		result.push_back(*up.end());
		up.pop_back();
	}
	int i;
	for (i = 0; i < up.size(); i+=2) {
		result.push_back(up[i] * up[i + 1]);
	}

	sort(down.begin(), down.end());
	if (down.size() % 2 != 0) {
		if(!zero) {
			result.push_back(down[i]);
		}
		down.pop_back();
	}
	for (i = 0; i < down.size(); i+= 2) {
		result.push_back(down[i] * down[i + 1]);
	}

	int sum = 0;
	for (auto v : result) {
		sum += v;
	}

	sum += one;

	cout << sum ;

	return 0;
}