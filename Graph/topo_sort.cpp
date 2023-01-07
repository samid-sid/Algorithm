/*
// problem link - https://cses.fi/problemset/task/1679/

5 3
1 2
3 1
4 5

5 4
1 2
2 3
3 1
4 5

6 6
5 2
5 0
4 0
4 1
2 3
3 1

 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1000;

vector<int> graph[N];
int visit[N];

stack<int> st;

bool dfs(int src)
{
    visit[src] = 1;

    for (auto adj : graph[src])
    {

        if (!visit[adj])
        {
            if (dfs(adj) == true)
                return true;
        }
        else if (visit[adj] == 1)
            return true;
    }
    visit[src] = 2;
    st.push(src);
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
    bool cycle = false;
    for (int i = 0; i < node; i++)
    {
        if (!visit[i])
        {
            if (dfs(i))
            {
                cycle = true;
                break;
            }
        }
    }
    if (cycle)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        while (!st.empty())
        {
            /* code */
            cout << st.top() << " ";
            st.pop();
        }
    }
}