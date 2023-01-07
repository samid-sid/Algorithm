// problem link - https://cses.fi/problemset/task/1668

/*
5 3
1 2
1 3
4 5

Output ->
1 2 2 1 2
1 2 2 2 1
2 1 1 2 1
(2)  (1)
1 -- 2
|
3
(1)
(2)  (1)
4 -- 5
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1000;

vector<int> graph[N];
int visit[N];
int color[N];

bool dfs(int src)
{
    visit[src] = 1;

    for (auto adj : graph[src])
    {
        if (!visit[adj])
        {
            if (color[src] == 1)
                color[adj] = 2;
            else
                color[adj] = 2;

            // bool ok = dfs(adj);
            // if (!ok)
            // {
            //     return false;
            // }
            if(dfs(adj) == false) return false;
        }
        else
        {
            if (color[src] == color[adj])
                return false;
        }
    }
    return true;
}

int main()
{

    int node, edge;
    cin >> node >> edge;

    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool is_bicolorable = 1;
    for (int i = 1; i <= node; i++)
    {
        if (!visit[i])
        {
            color[i] = 1;
            // bool ok = dfs(i);
            // if (!ok)
            // {               
            //     is_bicolorable = 0;
            //     break;
            // }
            if(dfs(i) == false)
            {
                is_bicolorable = false;
                break;
            }
        }
    }

    if (is_bicolorable)
    {
        for (int i = 1; i <= node; i++)
        {
            cout << color[i] << " ";
        }
    }
    else
    cout << "Impossible" << endl;
}