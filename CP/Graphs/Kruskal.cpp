#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define nl cout << "\n"
#define db(x) cout << x << " "
#define fi(a, b) for (int i = a; i < b; i++)
#define fj(a, b) for (int j = a; j < b; j++)
#define fk(a, b) for (int k = a; k < b; k++)
#define F first
#define S second
template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
    for (auto &v : vec)
        is >> v;
    return is;
}
#define mxsize (int)1e6

vector<int> par(mxsize + 1), sz(mxsize + 1);
int find(ll node)
{
    if (par[node] == node)
        return node;

    return par[node] = find(par[node]); //path compression
}
void merge(ll a, ll b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (sz[a] < sz[b])
        swap(a, b);
    par[b] = a;
    sz[a] += sz[b]; //Union by size
}
void fun()
{
    int n, d;
    cin >> n >> d;
    fi(0, n + 1)
    {
        par[i] = i;
        sz[i] = 1;
    }
    vector<pair<ll, pair<int, int>>> adj;
    fi(1, n + 1)
    {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        adj.push_back({w, {x, y}});
    }
    sort(adj.begin(), adj.end());
    ll ans = 0;
    for (auto p : adj)
    {
        int x = p.S.F, y = p.S.S;
        if (find(x) != find(y))
        {
            ans += p.F;
            merge(x, y);
        }
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(20);
    cout << fixed;
#ifndef ONLINE_JUDGE
    freopen("/ATOM/input.txt", "r", stdin);
    freopen("/ATOM/output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        fun();
    }
}