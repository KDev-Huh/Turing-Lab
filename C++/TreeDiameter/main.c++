#include <iostream>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> farthestNode(int sn, const vector<vector<pair<int, int>>>& tree)
{
	vector<bool> visited(tree.size(), false);
	visited[0] = true;
	vector<int> dist(tree.size(), 0); // 거리를 저장
	queue<int> nq; // 지하고 연결된 것들 저장
	pair<int, int> fnode{ sn, 0 }; // 가장 먼 노드

	nq.push(sn);
	visited[sn] = true;
	dist[sn] = 0;
	while (!nq.empty()) {
		int num = nq.front(); nq.pop();
		for (auto [n, d] : tree[num]) {
			if (visited[n]) continue;
			nq.push(n);
			visited[n] = true;
			int path = dist[num] + d;
			dist[n] = path;

			if (fnode.second < path) {
				fnode = { n, dist[n] };
			}
		}
	}
	return fnode;
}

int main() {
	vector < vector<pair<int, int>>> tree{
		{},
		{{3, 2}},
		{{4, 4}},
		{{1, 2}, {4, 3}},
		{{2, 4}, {3, 3}, {5, 6}},
		{{4, 6}},
	};

	pair<int, int> firstValue = farthestNode(5, tree);
	pair<int, int> secoundValue = farthestNode(firstValue.first, tree);
	cout << secoundValue.second;

	return 0;
}