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
ll fastexp(ll a, ll n, ll nod)
{
    if (nod == 0)
        nod = LLONG_MAX;
    ll ans = 1;
    while (n)     {
        if (n & 1)
            ans = (ans * a) % nod;
        a = (a * a) % nod;
        n >>= 1;
    }
    return ans;
}
#define mxsize (int)1e6
class dsu {
public:
    vector<int> par, sz;
    dsu(int _n)
    {
        par = sz = vector<int>(_n + 1, 1);
        iota(par.begin(), par.end(), 0);
    }

    int find(int node)
    {
        if (par[node] == node)
            return node;

        return par[node] = find(par[node]); //path compression
    }

    bool merge(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return 0;
        if (sz[a] < sz[b])
            swap(a, b);
        par[b] = a;
        sz[a] += sz[b]; //Union by size
        return 1;
    }
};

void fun()
{
    dsu d(10);
    int a, b;
    cin >> a >> b;
    d.merge(a, b);
    cout << d.find(a) << " " << d.find(b) << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/ATOM/input.txt", "r", stdin);
    freopen("/ATOM/output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)     {
        fun();
    }
}