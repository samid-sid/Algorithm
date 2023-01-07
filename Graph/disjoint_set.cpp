#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 1e3;

vector<PII> edgeList;
vector<int> parent;
int find_parent(int x)
{
    if (parent[x] == -1)
        return x;
    return find_parent(parent[x]);
}

int main()
{
    int n, e;
    cin >> n >> e;

    parent.resize(n, -1);

    while (e--)
    {
        int u, v;
        cin >> u >> v;
        PII pr = {u, v};
        edgeList.push_back(pr);
    }
    bool cycle = false;
    for (int i = 0; i < edgeList.size(); i++)
    {
        PII pr = edgeList[i];
        int a = pr.first;
        int b = pr.second;

        int prnt_A = find_parent(a);
        int prnt_B = find_parent(b);

        if (prnt_A == prnt_B)
        {
            cycle = true;
            break;
        }
        else
        {
            parent[prnt_A] = prnt_B;
        }
    }

    if(cycle){cout << "Cycle Exist"<<endl;}
    else {cout << "Cycle Not Exist"<<endl;}
}
/*

4 4
0 1
0 2 
1 2 
2 3


7 5
0 1
1 2 
2 3
4 5
5 6

*/