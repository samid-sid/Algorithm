// problem link - https://cses.fi/problemset/task/1678/

/*
4 4
1 3
2 1
2 4
3 4
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;

vector<int> graph[N];
int visit[N];

bool dfs(int src)
{
    visit[src] = 1;

    for(auto adj:graph[src])
    {
        if(!visit[adj])
        {
            if(dfs(adj) == true) return true;
        }
        else if(visit[adj] == 1) return true;
    }
    visit[src] = 2;
    return false;
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
    }
    bool ok = 0;
    for (int i = 1; i <= node; i++)
    {
        if(!visit[i])
        {
            if(dfs(i))
            {
                ok = 1;
                break;
            }
     
        }
    }
    if(ok)
    cout << "Cycle Exist " <<endl;
    else
     cout << "Cycle Not Exist" <<endl;
}
