#include <iostream>
#include <vector>

using namespace std;

void findCombinations(vector<vector<int>>& results, vector<int>& findingValue, int i, int n, int k) {
	if (findingValue.size() == k) {
		results.push_back(findingValue);
		return;
	}

	for (int j = i; j <= n; j++) {
		findingValue.push_back(j);
		findCombinations(results, findingValue, j + 1, n, k);
		findingValue.pop_back();
	}
}

vector<vector<int>> findCombinations(int n, int k) {
	vector<vector<int>> results;
	vector<int> findingValue;
	
	findCombinations(results, findingValue, 1, n, k);

	return results;
}

int main() {
	int n, k;

	cin >> n >> k;

	auto res = findCombinations(n, k);

	cout << "[";

	for (auto nums : res) {
		cout << "[";
		for (auto n : nums)
			cout << n << ", ";
		cout << "\b\b], ";
	}
	
	if (res.size()) cout << "\b\b";
	cout << "]\n";


	return 0;
}