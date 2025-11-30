#include <iostream>
#include <vector>

using namespace std;

void printDP(vector<vector<int>>& dp) {
	for (auto v : dp) {
		for (auto i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
}

int minDistance(string word1, string word2) {
	const int m = word1.size();
	const int n = word2.size();

	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

	for (int r = 1; r <= m; r++)
		dp[r][0] = r;

	for (int c = 1; c <= n; c++)
		dp[0][c] = c;

	for (int r = 1; r <= m; r++) {
		for (int c = 1; c <= n; c++) {
			if (word1[r - 1] == word2[c - 1])
				dp[r][c] = dp[r - 1][c - 1];
			else 
				dp[r][c] = min({dp[r - 1][c - 1], dp[r - 1][c], dp[r][c - 1]}) + 1;
		}
	}

	//printDP(dp);

	return dp[m][n];
}

int main() {
	vector<vector<string>> data{ {"horse", "ros"}, {"intention", "execution"}, {"cat", "cut"} };

	for (auto str : data) {
		cout << minDistance(str[0], str[1]) << endl;
	}


	return 0;
}