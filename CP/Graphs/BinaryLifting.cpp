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

//To give kth ancestor of a node in O(logn) time

int n;
vector<int> adj[mxsize];
int up[mxsize][20];
void binary_lifting(int node, int par)
{
    up[node][0] = par;
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
int getKthancestor(int node, int k)
{
    int count = 0;
    while (k)
    {
        if (k % 2)
        {
            if (up[node][count] == -1)
                return -1;
            node = up[node][count];
        }
        count++;
        k /= 2;
    }
    return node;
}

void fun()
{
    //check the input format
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

    //If kth ancestor does not exist, -1 will be printed
    while (q--)
    {
        int node, k;
        cin >> node >> k;
        cout << getKthancestor(node, k) << "\n";
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
    cin >> t;
    while (t--)
    {
        fun();
    }
}