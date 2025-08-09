#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
using VictimList = vector<int>;
using Graph = vector<VictimList>;



class VictimNetwork {
private:
	int cntNode;
	Graph graph;
public:
	VictimNetwork(int cnt) : cntNode(cnt), graph(cnt + 1)
	{}

	void pushEdge(int src, int dest)
	{
		graph[dest].push_back(src);
	}

	VictimList findVictim()
	{
		queue<int> proc;
		vector<int> cntChild(cntNode + 1, 0);

		for (int i = 1; i <= cntNode; i++)
		{
			int child = 1;
			vector<bool> visited(cntNode + 1, false);
			visited[0] = true;

			proc.push(i);
			visited[i] = true;

			while (!proc.empty())
			{
				int node = proc.front(); proc.pop();

				for (auto& an : graph[node]) {
					if (!visited[an]) {
						child++;
						proc.push(an);
						visited[an] = true;
					}
				}
			}

			cntChild[i] = child;
		}

		vector<int> result;
		int max = *max_element(cntChild.begin(), cntChild.end());

		for (int i = 1; i <= cntNode; i++)
			if (cntChild[i] == max)
				result.push_back(i);

		return result;
	}
};

int main() {

	vector<string> data{
		"5 4 3 1 3 2 4 3 5 3",
		"6 5 1 2 2 3 3 1 1 4 5 6"
	};

	for (auto& sin : data)
	{
		stringstream ss(sin);

		int cntNode, cntRel;
		ss >> cntNode >> cntRel;

		VictimNetwork vn(cntNode);

		int src, dest;
		for (int i = 0; i < cntRel; i++) {
			ss >> src >> dest;
			vn.pushEdge(src, dest);
		}
		for (auto& n : vn.findVictim())
			cout << n << " ";
		cout << endl;
	}

	return 0;
}