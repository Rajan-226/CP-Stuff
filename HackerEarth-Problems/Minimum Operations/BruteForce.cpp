#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
class segTree
{
public:
    vector<pair<int, int>> tree;
    void make(vector<int> &arr, int n)
    {
        tree = vector<pair<int, int>>(n * 4 + 100);
        build_tree(1, 1, n, arr);
    }
    pair<int, int> queryMin(int si, int ss, int se, int qa, int qb)
    {
        if (ss > qb || se < qa)
            return {1e9 + 100, 0};
        if (ss >= qa && se <= qb)
            return tree[si];

        int mid = (ss + se) / 2;
        auto left = queryMin(2 * si, ss, mid, qa, qb);
        auto right = queryMin(2 * si + 1, mid + 1, se, qa, qb);

        return min(left, right);
    }
    void build_tree(int si, int ss, int se, vector<int> &arr)
    {
        if (ss == se)
        {
            assert(arr[ss] >= 1 && arr[ss] <= (int)1e9);
            tree[si] = {arr[ss], ss};
            return;
        }
        int mid = (ss + se) / 2;
        build_tree(2 * si, ss, mid, arr);
        build_tree(2 * si + 1, mid + 1, se, arr);
        tree[si] = min(tree[2 * si], tree[2 * si + 1]);
    }
};
int N;
vector<int> A;
segTree s;
int help()
{
    queue<pair<int, pair<int, int>>> q;
    q.push({-1, {1, N}});
    int ans = 0;
    while (!q.empty())
    {
        int last = q.front().F;
        int l = q.front().S.F;
        int r = q.front().S.S;
        q.pop();
        if (l == r)
        {
            ans += (A[l] != last);
            continue;
        }
        auto p = s.queryMin(1, 1, N, l, r);
        ans += (p.F != last);
        if (p.S + 1 <= r)
            q.push({p.F, {p.S + 1, r}});
        if (l <= p.S - 1)
            q.push({p.F, {l, p.S - 1}});
    }
    return ans;
}
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("/ATOM/HackerEarth Problems/Minimum Operations/input.txt", "r", stdin);
    freopen("/ATOM/HackerEarth Problems/Minimum Operations/output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int t_i = 0; t_i < T; t_i++)
    {
        cin >> N;
        A = vector<int>(N + 1);
        for (int i_A = 1; i_A <= N; i_A++)
            cin >> A[i_A];

        s.make(A, N);

        cout << help() << "\n";
    }
}