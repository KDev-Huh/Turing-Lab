#include <iostream>
#include <vector>
#include <limits>

using namespace std;

//아직 완성못함

void dijkstra(const vector<vector<int>>&map)
{
    const int V = map.size();
    const int INF = numeric_limits<int>::max();
    vector<bool> complete(V, false);
    vector<int> dist(V, INF);
    dist[0] = 0;
    complete[0]=true;

    for (int i = 0; i < V;i++)
    {
        int min = INF;
        int x;
        for (int j = 0; j < V; j++)
        {
            if (map[i][j] != 0 && complete[j]==false) {
                if (min > map[i][j])
                {
                    min=map[i][j];
                    x=j;
                }
            }
        }
        dist[x]=min;
        complete[x]=true;
        //printf("%d %s\n",x,complete[1] ? "true" : "false");
    }
}

int main()
{
    vector<vector<int>> map(
    {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0},
    });
    dijkstra(map);

    return 0;
}