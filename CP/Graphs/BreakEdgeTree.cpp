#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int, int>> adj[100005];
int dp[100005][2];
void dfs(int node, int par)
{
    int ans = 0;
    int max1 = 0, max2 = 0;
    for (auto v : adj[node])
    {
        int child = v.first;
        int weight = v.second;

        if (child == par)
            continue;
        dfs(child, node);

        ans += dp[child][1]; //optimal value without taking this edge

        int now = -dp[child][1] + dp[child][0] + weight; //optimal value after taking this edge
        if (now > max1)
        {
            max2 = max1;
            max1 = now;
        }
        else if (now > max2)
            max2 = now;
    }
    dp[node][0] = ans + max1;        //Including this node in one path or not in any path
    dp[node][1] = ans + max1 + max2; //Including this node in two paths or one path or not in any path, whatever is most optimal
}
void fun()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        adj[i].clear();
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1, -1);
    cout << dp[1][1] << "\n";
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
        fun();
}