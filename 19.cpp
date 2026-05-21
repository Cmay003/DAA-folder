#include <iostream>
#include <climits>
using namespace std;

struct Edge
{
    int u, v, w;
};

int main()
{
    int V, E;
    cin >> V >> E;

    Edge edges[100];

    for(int i = 0; i < E; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int src;
    cin >> src;

    int dist[100];

    for(int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for(int i = 1; i <= V - 1; i++)
    {
        for(int j = 0; j < E; j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    cout << "Vertex\tDistance\n";

    for(int i = 0; i < V; i++)
        cout << i << "\t" << dist[i] << endl;

    return 0;
}