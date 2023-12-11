#include <bits/stdc++.h>
using namespace std;
#define int long long
class segTree
{
public:
    vector<int> tree;
    segTree(vector<int> arr, int n)
    {
        tree = vector<int>(n * 4 + 100, 0);
        build_tree(1, 1, n, arr);
    }

    int query(int si, int ss, int se, int qa, int qb)
    {
        if (ss > qb || se < qa)
            return -1e18;
        if (ss >= qa && se <= qb)
            return tree[si];
        int mid = (ss + se) / 2;
        int left = query(2 * si, ss, mid, qa, qb);
        int right = query(2 * si + 1, mid + 1, se, qa, qb);

        return max(left, right);
    }

    void build_tree(int si, int ss, int se, vector<int> &arr)
    {
        if (ss == se)
        {
            tree[si] = arr[ss];
            return;
        }
        int mid = (ss + se) / 2;
        build_tree(2 * si, ss, mid, arr);
        build_tree(2 * si + 1, mid + 1, se, arr);
        tree[si] = max(tree[2 * si], tree[2 * si + 1]);
    }
};
int skipUpdate(int N, int Q, vector<vector<int>> updates)
{
    vector<int> a(N + 5);
    for (auto v : updates)
    {
        a[v[0]] += v[2];
        a[v[1] + 1] -= v[2];
    }
    for (int i = 1; i <= N; i++)
        a[i] += a[i - 1];

    segTree s(a, N);
    int ans = LLONG_MAX;
    for (auto v : updates)
    {
        int l = v[0], r = v[1], x = v[2];
        int left = l == 1 ? -1 : s.query(1, 1, N, 1, l - 1);
        int right = r == N ? -1 : s.query(1, 1, N, r + 1, N);
        int center = s.query(1, 1, N, l, r) - x;
        ans = min(ans, max({left, center, right}));
    }
    return ans;
}

signed main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("/ATOM/HackerEarth Problems/Minimize Maximum/input.txt", "r", stdin);
    freopen("/ATOM/HackerEarth Problems/Minimize Maximum/output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        int Q;
        cin >> Q;
        vector<vector<int>> updates(Q, vector<int>(3));
        for (int i_updates = 0; i_updates < Q; i_updates++)
        {
            for (int j_updates = 0; j_updates < 3; j_updates++)
            {
                cin >> updates[i_updates][j_updates];
            }
        }

        long long out_;
        out_ = skipUpdate(N, Q, updates);
        cout << out_;
        cout << "\n";
    }
}