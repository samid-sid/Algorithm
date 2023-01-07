#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> graph[N];
int visit[N];
void dfs(int src)
{
    // static int visit[N]= {};

    visit[src] = 1;

    cout << src << " ";

    for(int val: graph[src])
    {
        if(visit[val] == 0)
        {
            dfs(val);
        }
    }

}

void dfs_iterative(int src){
    stack<int> st;
    st.push(src);
    while (!st.empty())
    {
       int tmp = st.top();
       st.pop();
       if(!visit[tmp])
       {
        visit[tmp] = 1;
        cout << tmp << " ";
       }

       for(auto adj : graph[tmp])
       {
         if(!visit[adj]){
            st.push(adj);
         }
       }
    }
    
}

void bfs(int src)
{
    static int visit[N]= {};
    queue<int> q;

    q.push(src);
    visit[src] = 1;

    while(!q.empty())
    {

        int temp = q.front();
        q.pop();

        cout << temp << " ";

        for(int val : graph[temp])
        {
            if(visit[val] == 0)
            {
                q.push(val);
                visit[val] = 1;
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
    cout << endl;
    dfs_iterative(1);
    // dfs(1);

//    for(int i=0 ;i<=node;i++)
//    {
//     cout << i << " -> ";
//     for(auto adj:graph[i])
//     {
//         cout << adj << " ";
//     }
//     cout << endl;
//    }
    // bfs(1);


    return 0;

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



5 6
1 2 
1 3
2 4
3 4
3 5
4 5

multiedge and self loop

4 10
1 2
1 2
1 2
1 4
2 3
2 4
2 4
3 3
3 4
4 4



simulate dfs with or without recursion

6 8
0 2
0 4
0 5
1 4
1 5
2 3
2 4
4 5



*/