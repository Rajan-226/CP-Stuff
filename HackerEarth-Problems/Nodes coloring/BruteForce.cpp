#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int long long

int n, m;
queue<pair<int, int>> q;
int A[1000][1000];
int dis[1000][1000];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool isValid(int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < m;
}
void bfs()
{
    q.push({0, 0});
    dis[0][0] = 0;
    while (!q.empty())
    {
        int px = q.front().first;  //parent x
        int py = q.front().second; //parent y
        q.pop();
        for (int j = 0; j < 4; j++)
        {
            int nx = px + dx[j]; //new x
            int ny = py + dy[j]; //new y
            if (isValid(nx, ny))
            {
                int req = 1; //to move to next cell
                if (A[nx][ny] > dis[px][py])
                    req = (A[nx][ny] - dis[px][py]) + (A[nx][ny] % 2 == dis[px][py] % 2);
                if ((dis[px][py] + req) < dis[nx][ny])
                {
                    q.push({nx, ny});
                    dis[nx][ny] = dis[px][py] + req;
                }
            }
        }
    }
}

int fun()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
            dis[i][j] = LLONG_MAX;
        }
    }
    if (n == 1 && m == 1)
        return 0;
    if (n == 1 && A[0][1] > 1)
        return -1;
    if (m == 1 && A[1][0] > 1)
        return -1;
    if (n != 1 && m != 1 && A[0][1] > 1 && A[1][0] > 1)
        return -1;
    bfs();
    assert(dis[n - 1][m - 1] < LLONG_MAX);
    return dis[n - 1][m - 1];
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/ATOM/input.txt", "r", stdin);
    freopen("/ATOM/output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        cout<<fun()<<"\n";
    }
}