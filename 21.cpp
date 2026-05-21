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

    int key[100], parent[100];
    bool mstSet[100];

    for(int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int count = 0; count < V - 1; count++)
    {
        int minKey = INT_MAX, u;

        for(int v = 0; v < V; v++)
        {
            if(!mstSet[v] && key[v] < minKey)
            {
                minKey = key[v];
                u = v;
            }
        }

        mstSet[u] = true;

        for(int v = 0; v < V; v++)
        {
            if(graph[u][v] &&
               !mstSet[v] &&
               graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int total = 0;

    for(int i = 1; i < V; i++)
        total += graph[i][parent[i]];

    cout << "Minimum Spanning Weight: " << total;

    return 0;
}