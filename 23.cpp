#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, w;
};

bool compare(Edge a, Edge b)
{
    return a.w > b.w;
}

int parent[100];

int find(int i)
{
    while(parent[i] != i)
        i = parent[i];

    return i;
}

void unionSet(int a, int b)
{
    parent[a] = b;
}

int main()
{
    int V;
    cin >> V;

    int graph[100][100];

    Edge edges[100];
    int edgeCount = 0;

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            cin >> graph[i][j];

            if(graph[i][j] != 0 && i < j)
            {
                edges[edgeCount++] = {i, j, graph[i][j]};
            }
        }
    }

    sort(edges, edges + edgeCount, compare);

    for(int i = 0; i < V; i++)
        parent[i] = i;

    int total = 0, count = 0;

    for(int i = 0; i < edgeCount && count < V - 1; i++)
    {
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        if(a != b)
        {
            total += edges[i].w;
            unionSet(a, b);
            count++;
        }
    }

    cout << "Maximum Spanning Weight: " << total;

    return 0;
}