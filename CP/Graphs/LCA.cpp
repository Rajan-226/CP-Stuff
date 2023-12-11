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
vector<int> adj[mxsize];
int up[mxsize][20];
vector<int> depth(mxsize);
void binary_lifting(int node, int par)
{
    up[node][0] = par;
    if (par != -1)
        depth[node] = depth[par] + 1;
    for (int i = 1; i < 20; i++)
    {
        //answer to go 2^i up will be equivalent to
        //go two times 2^(i-1) up
        //as 2^(i-1)+2^(i-1) = 2*2^(i-1)= 2^i
        if (up[node][i - 1] != -1)
            up[node][i] = up[up[node][i - 1]][i - 1];
        else
            up[node][i] = -1;
    }

    for (auto child : adj[node])
    {
        if (child == par)
            continue;
        binary_lifting(child, node);
    }
}
int lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);

    //a will be a node at greater depth
    int dif = depth[a] - depth[b];
    int count = 0;
    while (dif)
    {
        if (dif % 2)
        {
            assert(up[a][count] != -1);
            a = up[a][count];
        }
        count++;
        dif /= 2;
    }
    assert(depth[a] == depth[b]);
    if (a == b)
        return a;
    for (int i = 19; i >= 0; i--)
    {
        if (up[a][i] != -1 && up[a][i] != up[b][i])
        {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

void fun()
{
    //check the input format
    int n;
    cin >> n;
    int q;
    cin >> q;
    for (int i = 0; i <= n; i++)
    {
        adj[i].clear();
    }
    for (int i = 2; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        // v = i;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    binary_lifting(1, -1);
    //up[node][0] will give direct parent
    //depth[node] will give 0 based depth
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
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
    // cin >> t;
    while (t--)
    {
        fun();
    }
}