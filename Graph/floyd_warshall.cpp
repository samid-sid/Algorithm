#include <bits/stdc++.h>
using namespace std;
const int N = 1e2;
const int INF = 1e9;
int dis[N][N];
int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                dis[i][j] = 0;
            }
            else
            dis[i][j] = INF;
        }
    }

    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = w;
    }

    for(int k = 1;k<=n;k++)
    {
        for(int u=1;u<=n;u++)
        {
            for(int v=1;v<=n;v++)
            {
                dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
}

/*
4 4
1 2 5
2 4 3
3 1 2
3 4 50

*/