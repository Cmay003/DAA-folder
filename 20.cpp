#include <iostream>
#include <climits>
using namespace std;

#define INF 99999

int shortestPath(int graph[100][100], int u, int v, int k, int V)
{
    if(k == 0 && u == v)
        return 0;

    if(k == 1 && graph[u][v] != INF)
        return graph[u][v];

    if(k <= 0)
        return INF;

    int res = INF;

    for(int i = 0; i < V; i++)
    {
        if(graph[u][i] != INF && u != i && v != i)
        {
            int rec = shortestPath(graph, i, v, k - 1, V);

            if(rec != INF)
                res = min(res, graph[u][i] + rec);
        }
    }

    return res;
}

int main()
{
    int V;
    cin >> V;

    int graph[100][100];

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            cin >> graph[i][j];

            if(graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    int u, v, k;
    cin >> u >> v;
    cin >> k;

    int ans = shortestPath(graph, u, v, k, V);

    if(ans == INF)
        cout << "No path of length k is available";
    else
        cout << "Weight of shortest path = " << ans;

    return 0;
}