// problem link - https://cses.fi/problemset/task/1192

/*
5 8
########
#..#...#
####.#.#
#..#...#
########
Output -> 3

while there exists an empty cell
    - find an empty unvisited cell
    - run bfs() from that cell
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1002;
typedef pair<int, int> PII;
int maze[N][N];
int visit[N][N];
int n, m;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool is_safe(PII val)
{
    int x = val.first;
    int y = val.second;

    if (x >= 0 && x < n && y >= 0 && y < m)
    {
        return true;
    }
    return false;
}

bool is_room(PII val)
{
    int x = val.first;
    int y = val.second;

    if (maze[x][y] == 1)
    {
        return true;
    }
    return false;
}
void bfs(PII src)
{
    queue<PII> q;
    q.push(src);
    visit[src.first][src.second] = 1;
    while (!q.empty())
    {
        PII tmp = q.front();
        q.pop();
        int x = tmp.first;
        int y = tmp.second;

        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            PII x = {new_x,new_y};

            if (is_safe(tmp) && is_room(tmp) && !visit[new_x][new_y])
            {
                visit[new_x][new_y] = 1;
                q.push(x);
            }
        }
    }
}
void dfs(PII src)
{
    int x = src.first;
    int y = src.second;
    visit[x][y] = 1;

    for(int i=0;i<4;i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        PII tmp = {new_x,new_y};

        if(is_safe(tmp) && is_room(tmp) && !visit[new_x][new_y])
        {
            dfs(tmp);
        }

    }
}

int main()
{
    // int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string st;
        cin >> st;

        for (int j = 0; j < m; j++)
        {
            if (st[j] == '.')
            {
                maze[i][j] = 1;
            }
        }
    }
    int room = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if(visit[i][j] == 0 && maze[i][j] == 1){
                room++;
                dfs({i,j});
            }
        }
    }

    cout << room << endl;
}