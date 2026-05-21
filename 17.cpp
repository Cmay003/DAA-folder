#include <iostream>
using namespace std;

bool visited[100], recStack[100];

bool dfs(int graph[100][100], int v, int node)
{
    visited[node] = true;
    recStack[node] = true;

    for(int i = 0; i < v; i++)
    {
        if(graph[node][i])
        {
            if(!visited[i] && dfs(graph, v, i))
                return true;

            else if(recStack[i])
                return true;
        }
    }

    recStack[node] = false;

    return false;
}

int main()
{
    int v;
    cin >> v;

    int graph[100][100];

    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            cin >> graph[i][j];

    bool cycle = false;

    for(int i = 0; i < v; i++)
    {
        if(!visited[i])
        {
            if(dfs(graph, v, i))
            {
                cycle = true;
                break;
            }
        }
    }

    if(cycle)
        cout << "Yes Cycle Exists";
    else
        cout << "No Cycle Exists";

    return 0;
}