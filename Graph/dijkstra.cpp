#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 1e3;

vector<pair<int,int>> graph[N];
vector<int> visit;
vector<int> dis;
int node,edge;
// int select_a_node()
// {
//     int selected_node = -1;
//     for(int i=1;i<=node;i++)
//     {
//         if(visit[i]) continue;

//         if()
//     }
// }

int main()
{
    cin >> node >> edge;
    visit.resize(node,0);
    dis.resize(node,INT_MAX);

    while(edge--)
    {
        int u,v,w;
        cin >> u >> v >> w;

        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    int src = 1;

    dis[src] = 0;

    for(int i=0;i<node;i++)
    {
        int select_nd = -1;
        for(int j=1;j<=node;j++)
        {
            if(visit[j]) continue;
            if(select_nd == -1 || dis[select_nd] > dis[j])
            {
                select_nd = j;
            }
        }

        visit[select_nd] = 1;
        for(auto adj: graph[select_nd])
        {
            int eg = adj.first;
            int cost = adj.second;
            int distance = dis[select_nd] + dis[cost];
            if(distance < dis[eg])
            {
                dis[eg] = distance;
            } 
        }
        
    }

    for(int i=1;i<=node;i++)
    {
        cout << src << " -> " << dis[i] << endl;
    }
}
/*
6 10
1 2 6
1 3 1 
1 4 5 
2 3 5
2 5 3 
3 4 5
3 5 6
3 6 4
4 6 2
5 6 6


*/