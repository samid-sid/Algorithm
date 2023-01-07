#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
typedef pair<int, int> PII;
int maze[N][N];
int visit[N][N];
int level[N][N];
int n, m;

bool is_inside(PII val)
{
    int x = val.first;
    int y = val.second;

    if(x >= 0 && x <n && y >= 0 && y<m)
    return true;

    return false;
}

bool is_door(PII val)
{
    int x = val.first;
    int y = val.second;
    if(maze[x][y] == 0)
    return true;
    
    return false;
}

void bfs(PII src)
{
    queue<PII> q;
    q.push(src);
    level[src.first][src.second] = 0;
    visit[src.first][src.second] = 1;

    int dx[] = {0,0,-1,1};
    int dy[] = {1,-1,0,0};

    while (!q.empty())
    {
        PII temp = q.front();
        q.pop();

        int x = temp.first;
        int y = temp.second;

        for(int i=0;i<4;i++)
        {
            int new_x = x+dx[i];
            int new_y = y+dy[i];

            PII  tmp = {new_x,new_y};

            if(is_inside(tmp) && is_door(tmp) && visit[new_x][new_y] == 0)
            {
               visit[new_x][new_y] = 1;
               q.push(tmp);
               level[new_x][new_y] = level[x][y] +1;
            }
        }

    }
    

}
int main()
{
    cin >> n >> m;
    PII src, des;
    for (int i = 0; i < n; i++)
    {
        string st;
        cin >> st;
        for (int j = 0; j < m; j++)
        {
            char ch = st[j];
            if (ch == '#')
            {
                maze[i][j] = -1;
            }
            else if (ch == 'A')
            {
                src = {i, j};
            }
            else if (ch == 'B')
            {
                des = {i,j};
            }
        }
    }

    // memset(level,-1,sizeof(level));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            level[i][j] = -1;
        }
    }

    bfs(src);

    if(visit[des.first][des.second]==0)
    {
        cout << "NO" <<endl;
    }
    else 
    {
        cout << "YES" << endl;
        cout << level[des.first][des.second];
    }

    return 0;
}

/*
5 8
########
#.A#...#
#.##.#B#
#......#
########


Step 1->
make a graph of this string ;


direction 

(x,y) right -> (x,y+1)
(x,y) left ->  (x,y-1)
(x,y)  up ->   (x-1,y)
(x,y) down ->  (x+1,y)

dx[] = {0,0,-1,1};
dy[] = {1,-1,0,0};

consition :
1) is the cell withih the maze 
2) is the cell forbidden
3) is the cell visited

*/