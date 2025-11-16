#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> findNewIntervals(vector<pair<int, int>>& intervals, const pair<int, int> newInterval) {
	int first = newInterval.first;
	int second = newInterval.second;

	vector<pair<int, int>> results;

	int idx = 0;
	while (intervals[idx].second < first) {
		results.push_back(intervals[idx++]);
	}

	int start = intervals[idx].first < first ? intervals[idx].first : first, end;
	while (intervals[idx].first <= second) {
		end = intervals[idx].second > second ? intervals[idx].second : second;
		idx++;
	}
	results.push_back({ start, end });

	while (idx < intervals.size()) {
		results.push_back(intervals[idx++]);
	}

	return results;
}

int main() {
	vector<pair<int, int>> intervals{
		{1, 3}, {6, 9}
	};

	pair<int, int> newInterval{ 2, 5 };

	vector<pair<int, int>> results = findNewIntervals(intervals, newInterval);

	cout << "[";
	for (auto p : results) {
		cout << "[" << p.first << ", " << p.second << "], ";
	}
	cout << "]";


	return 0;
}