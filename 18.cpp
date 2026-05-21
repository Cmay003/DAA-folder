#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int V;
    cin >> V;

    int graph[100][100];

    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            cin >> graph[i][j];

    int src;
    cin >> src;

    int dist[100], visited[100], parent[100];

    for(int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for(int count = 0; count < V - 1; count++)
    {
        int minDist = INT_MAX, u;

        for(int i = 0; i < V; i++)
        {
            if(!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for(int v = 0; v < V; v++)
        {
            if(graph[u][v] && !visited[v] &&
               dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Vertex\tDistance\n";

    for(int i = 0; i < V; i++)
        cout << i << "\t" << dist[i] << endl;

    return 0;
}