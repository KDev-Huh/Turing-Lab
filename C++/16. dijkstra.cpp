#include <iostream>
#include <climits>
#include <vector>

using nvt = std::vector<int>;
using bvt = std::vector<bool>;
using nnvt = std::vector<nvt>;
const int INF = INT_MAX;

int minDistance(nvt& dist, const bvt& sptSet)
{
	int min = INF, minIdx = 0;

	for (int v = 0; v < dist.size(); v++)
	{
		if (!sptSet[v] && dist[v] <= min)
		{
			min = dist[v];
			minIdx = v;
		}
	}

	return minIdx;
}

void printDistance(const nvt& dist, int src)
{
	for (int i = 0; i < dist.size(); i++)
	{
		std::cout << "[" << src <<" -> " << i << "]: " << dist[i] << std::endl;
	}
}

void trailPath(const nvt& prev, int v)
{
	if (v == 0) return;

	trailPath(prev, prev[v]);

	std::cout << prev[v] << "->";
}

void tracePath(const nvt& prev)
{
	for (int i = 0; i < prev.size(); i++)
	{
		trailPath(prev, i);
		std::cout << i << std::endl;
	}
	
}

void dijkstra(const nnvt& graph, int src)
{
	nvt dist(graph.size(), INF);
	dist[src] = 0;
	bvt sptSet(graph.size(), false);
	nvt prev(graph.size(), 0);

	for (int i = 0; i < graph.size(); i++)
	{
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;

		
		for (int v = 0; v < graph.size(); v++)
		{
			if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
			{
				dist[v] = dist[u] + graph[u][v];
				prev[v] = u;
			}
		}
	}

	printDistance(dist, src);
	tracePath(prev);
}

int main()
{
	nnvt vt = {
		{ 0, 4,  0, 0,  0,  0,  0, 8,  0 },
		{ 4, 0,  8, 0,  0,  0,  0, 11, 0 },
		{ 0, 8,  0, 7,  0,  4,  0, 0,  2 },
		{ 0, 0,  7, 0,  9,  14, 0, 0,  0 },
		{ 0, 0,  0, 9,  0,  10, 0, 0,  0 },
		{ 0, 0,  4, 14, 10, 0,  2, 0,  0 },
		{ 0, 0,  0, 0,  0,  2,  0, 1,  6 },
		{ 8, 11, 0, 0,  0,  0,  1, 0,  7 },
		{ 0, 0,  2, 0,  0,  0,  6, 7,  0 }
	};

	dijkstra(vt, 0);

	return 0;
}