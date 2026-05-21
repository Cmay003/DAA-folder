#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int v;
    cin >> v;

    int graph[100][100];

    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            cin >> graph[i][j];

    int color[100];

    for(int i = 0; i < v; i++)
        color[i] = -1;

    queue<int> q;

    color[0] = 1;
    q.push(0);

    bool bipartite = true;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i = 0; i < v; i++)
        {
            if(graph[u][i])
            {
                if(color[i] == -1)
                {
                    color[i] = 1 - color[u];
                    q.push(i);
                }
                else if(color[i] == color[u])
                {
                    bipartite = false;
                }
            }
        }
    }

    if(bipartite)
        cout << "Yes Bipartite";
    else
        cout << "Not Bipartite";

    return 0;
}