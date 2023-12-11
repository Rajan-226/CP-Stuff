#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007
#define pi 3.141592653589
#define nl cout << "\n"
#define db(x) cout << x << " "
#define fi(a, b) for (int i = a; i < b; i++)
#define fj(a, b) for (int j = a; j < b; j++)
#define fk(a, b) for (int k = a; k < b; k++)
#define F first
#define S second

int fastexp(int a, int n, int nod = LLONG_MAX)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)
            ans = (ans * a) % nod;
        a = (a * a) % nod;
        n >>= 1;
    }
    return ans;
}
#define mxsize (int)3e5

void fun()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, 1e16));
    fi(0, m)
    {
        int u, v, x;
        cin >> u >> v >> x;
        x = min(dis[u][v], x);
        dis[u][v] = x;
        dis[v][u] = x;
    }
    fi(1, n + 1) dis[i][i] = 0;
    for (int k = 1; k <= n; k++)
    {
        // Including only first k nodes
        // and updating all the pairs
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    fi(1, n + 1)
    {
        if (dis[i][i] != 0) //can be negative if infinite negative cycle is there
        {
            // cout<<"Negative Cycle found\n";
            assert(0);
        }
    }
    
    int q;
    while(q--){
        int u,v;cin>>u>>v;
        if(dis[u][v]>=(int)1e16) dis[u][v]=-1;
        cout<<dis[u][v]<<"\n";
    }
}
/*

*/
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    cout << fixed;
    //#ifndef ONLINE_JUDGE
    //	freopen("/ATOM/input.txt", "r", stdin);
    //	freopen("/ATOM/output.txt", "w", stdout);
    //#endif
    int t = 1;
    // cin>>t;
    while (t--)
    {
        fun();
    }
}