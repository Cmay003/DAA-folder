#include <iostream>
using namespace std;

bool visited[100];

void dfs(int graph[100][100], int v, int curr)
{
    visited[curr] = true;

    for(int i = 0; i < v; i++)
    {
        if(graph[curr][i] && !visited[i])
            dfs(graph, v, i);
    }
}

int main()
{
    int v;
    cin >> v;

    int graph[100][100];

    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            cin >> graph[i][j];

    int src, dest;
    cin >> src >> dest;

    dfs(graph, v, src);

    if(visited[dest])
        cout << "Yes Path Exists";
    else
        cout << "No Such Path Exists";

    return 0;
}