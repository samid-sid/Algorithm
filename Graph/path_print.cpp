/*
problem : https://cses.fi/problemset/result/5241207/

Input:
5 5
1 2
1 3
1 4
2 3
5 4

Output:
3
1 4 5


*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
vector<int> graph[N];
int visit[N];
int parent[N];
vector<int> ans;

void bfs(int src)
{
  queue<int> q;
  visit[src] = 1;
  q.push(src);

  while (!q.empty())
  {
    int tmp = q.front();
    q.pop();

    for (auto adj : graph[tmp])
    {
      if (visit[adj] == 0)
      {
        visit[adj] = 1;
        parent[adj] = tmp;
        q.push(adj);
      }
    }
  }
}

int main(void)
{

  int nodes, edges;
  cin >> nodes >> edges;

  for (int i = 0; i < edges; i++)
  {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  
  bfs(1);

  if (visit[nodes] == 0)
  {
    cout << "IMPOSSIBLE"<<endl;
  }
  else
  {
    ans.push_back(nodes);
    int tmp = nodes;
    while (tmp != 1)
    {
      ans.push_back(parent[tmp]);
      tmp = parent[tmp];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto i : ans)
    {
      cout << i << " ";
    }
  }
}
