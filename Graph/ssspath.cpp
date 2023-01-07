#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> graph[N];
int visit[N];
int level[N];

void dfs(int src, int lvl)
{
    visit[src] = 1;
    level[src] = lvl;

    for(auto adj : graph[src]){
        if(!visit[adj])
        {
          dfs(adj,lvl+1);
        }
    }
}
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visit[src] = 1;

    level[src] = 0; //new line

    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();

        for(auto adj: graph[tmp])
        {
            if(!visit[adj])
            {
                visit[adj] = 1;
                level[adj] = level[tmp]+1;//new line
                q.push(adj);
            }
        }
    }
    
}
int main()
{
       int node , edge;
    cin >> node >> edge ;

    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // bfs(0);
    dfs (0,0);

    for(int i=0;i<node;i++){
        cout << "Node " <<i << " at level -> " << level[i] <<endl;
    }
}

/*

0 ---- 1 ----2 ----3----6
       |     |
       |     |
       5 ----4

7 7
0 1
1 2
1 5
2 3
2 4
3 6
4 5

*/