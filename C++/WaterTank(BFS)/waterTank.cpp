#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <set>

using namespace std;

pair<int, int> moveWater(int at, int bt, int aw, int bw) {
	if (aw + bw > bt)
		return { aw + bw - bt, bt };
	else
		return { 0, aw + bw };
}

void insertQueue(tuple<int, int, int> table, vector<vector<vector<bool>>>& visted, queue<tuple<int, int, int>>& q, int a, int b, int c) {
	auto [ta, tb, tc] = table;
	pair<int, int> value;

	value = moveWater(ta, tb, a, b);
	int v1 = value.first, v2 = value.second;
	if (!visted[v1][v2][c]) {
		q.push({ v1, v2, c });
		visted[v1][v2][c] = true;
	}

	value = moveWater(ta, tc, a, c);
	v1 = value.first, v2 = value.second;
	if (!visted[v1][b][v2]) {
		q.push({ v1, b, v2 });
		visted[v1][b][v2] = true;
	}

	value = moveWater(tb, ta, b, a);
	v1 = value.first, v2 = value.second;
	if (!visted[v2][v1][c]) {
		q.push({ v2, v1, c });
		visted[v2][v1][c] = true;
	}

	value = moveWater(tb, tc, b, c);
	v1 = value.first, v2 = value.second;
	if (!visted[a][v1][v2]) {
		q.push({ a, v1, v2 });
		visted[a][v1][v2] = true;
	}

	value = moveWater(tc, ta, c, a);
	v1 = value.first, v2 = value.second;
	if (!visted[v2][b][v1]) {
		q.push({ v2, b, v1 });
		visted[v2][b][v1] = true;
	}

	value = moveWater(tc, tb, c, b);
	v1 = value.first, v2 = value.second;
	if (!visted[a][v2][v1]) {
		q.push({ a, v2, v1 });
		visted[a][v2][v1] = true;
	}
}

set<int> findWaterTankC(tuple<int, int, int> table) {
	auto [ta, tb, tc] = table;
	vector<vector<vector<bool>>> visted(ta + 1, vector<vector<bool>>(tb + 1, vector<bool>(tc + 1, false)));

	set<int> result;

	queue<tuple<int, int, int>> q;

	visted[0][0][tc] = true;
	result.insert(tc);
	insertQueue(table, visted, q, 0, 0, tc);

	while (!q.empty()) {
		tuple<int, int, int> value = q.front(); q.pop();
		auto [a, b, c] = value;
		
		if (!a) result.insert(c);

		if (visted[a][b][c]) {
			insertQueue(table, visted, q, a, b, c);
		}
	}

	return result;
}


int main() {
	tuple<int, int, int> data{
		8, 9, 20
	};

	set<int> result = findWaterTankC(data);

	for (auto v : result) {
		cout << v << " ";
	}

	return 0;
}