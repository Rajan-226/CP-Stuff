#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second

class dsu
{
public:
    vector<int> par, sz;
    vector<bool> isColored;
    dsu(int _n, vector<bool> &temp)
    {
        par = sz = vector<int>(_n + 1, 1);
        isColored = temp;
        iota(par.begin(), par.end(), 0);
    }

    pair<int, int> find(int node)
    {
        if (par[node] == node)
            return {node, isColored[node]};

        pair<int, int> p = find(par[node]);
        par[node] = p.first;

        return p;
    }

    bool merge(int a, int b)
    {

        pair<int, int> a1 = find(a);
        pair<int, int> b1 = find(b);
        if (a1.S && b1.S) //both colored components
            return 0;
        if (a1.F == b1.F) //already connected
            return 0;

        bool colour;
        if (!a1.S && !b1.S) //both uncolored
            colour = 0;
        else                //one of them is colored
            colour = 1;

        a = a1.F;
        b = b1.F;

        isColored[a] = isColored[b] = colour;

        if (sz[a] < sz[b])
            swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        return 1;
    }
};

void fun()
{
    int n;
    cin >> n;
    assert(1 <= n && n <= 1000);
    vector<bool> a(n + 1);
    int total = 0;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        assert(k == 1 || k == 0);
        total += k;
        a[i] = k;
    }
    assert(total >= 1);
    vector<pair<int, pair<int, int>>> v;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            assert((x == 0 && i == j) || (x >= 1 && x <= 1e9));
            if (i > j)
                v.push_back({x, {i, j}});
        }
    }
    sort(v.begin(), v.end());
    dsu d(n + 5, a);
    int edges = 0;
    int ans = 0;
    for (auto i : v)
    {
        int x = i.S.F, y = i.S.S;
        if (d.merge(x, y))
        {
            ans += i.F;
            edges++;
            // cout << x << " " << y << " " << i.F << "\n";
            if (edges == n - total)
                break;
        }
    }
    assert(edges == n - total);
    cout << ans << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/ATOM/HackerEarth Problems/Nodes coloring/input.txt", "r", stdin);
    freopen("/ATOM/HackerEarth Problems/Nodes coloring/output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    assert(1 <= t && t <= 10);
    while (t--)
    {
        fun();
    }
}