#include <bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
class segTree
{
public:
    vector<pair<int, int>> tree1, tree2;
    void make(vector<int> arr, int n)
    {
        tree1 = tree2 = vector<pair<int, int>>(n * 4 + 100);
        build_tree(1, 1, n, arr);
    }

    pair<int, int> queryMin(int si, int ss, int se, int qa, int qb)
    {
        if (ss > qb || se < qa)
            return {1e6 + 10, 0};
        if (ss >= qa && se <= qb)
            return tree1[si];

        int mid = (ss + se) / 2;
        auto left = queryMin(2 * si, ss, mid, qa, qb);
        auto right = queryMin(2 * si + 1, mid + 1, se, qa, qb);

        return min(left, right);
    }

    pair<int, int> queryMax(int si, int ss, int se, int qa, int qb)
    {
        if (ss > qb || se < qa)
            return {-1e6 - 10, 0};
        if (ss >= qa && se <= qb)
            return tree2[si];

        int mid = (ss + se) / 2;
        auto left = queryMax(2 * si, ss, mid, qa, qb);
        auto right = queryMax(2 * si + 1, mid + 1, se, qa, qb);

        return max(left, right);
    }
    void build_tree(int si, int ss, int se, vector<int> &arr)
    {
        if (ss == se)
        {
            assert(arr[ss - 1] >= (int)-1e6 && arr[ss - 1] <= 1e6);
            tree1[si] = tree2[si] = {arr[ss - 1], ss};
            return;
        }
        int mid = (ss + se) / 2;
        build_tree(2 * si, ss, mid, arr);
        build_tree(2 * si + 1, mid + 1, se, arr);
        tree1[si] = min(tree1[2 * si], tree1[2 * si + 1]);
        tree2[si] = max(tree2[2 * si], tree2[2 * si + 1]);
    }
};
segTree s;
set<pair<int, int>> now;
void help(int temp, int l, int r, int n)
{
    if (!temp)
        return;

    auto p = s.queryMax(1, 1, n, l, r);
    now.insert(p);
    if (p.S != l)
        help(temp - 1, l, p.S - 1, n);
    if (p.S != r)
        help(temp - 1, p.S + 1, r, n);

    p = s.queryMin(1, 1, n, l, r);
    now.insert(p);
    if (p.S != l)
        help(temp - 1, l, p.S - 1, n);
    if (p.S != r)
        help(temp - 1, p.S + 1, r, n);
}
vector<int> maxProduct(int N, int Q, vector<int> A, vector<vector<int>> queries)
{
    s.make(A, N);
    vector<int> ans;
    for (auto v : queries)
    {
        int l = v[1], r = v[2];
        assert(r - l + 1 >= v[0] + 1);
        assert(l >= 1 && l <= r);
        assert(r <= N);

        help(v[0] + 1, l, r, N);
        vector<pair<int, int>> dif(now.begin(), now.end());
        int sz = dif.size();
        assert(sz >= v[0] + 1);
        if (v[0] == 1)
            ans.push_back(max(dif[0].F * dif[1].F, dif[sz - 1].F * dif[sz - 2].F));
        else
            ans.push_back(max(dif[sz - 1].F * dif[sz - 2].F * dif[sz - 3].F, dif[0].F * dif[1].F * dif[sz - 1].F));
        now.clear();
    }
    return ans;
}

signed main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("/ATOM/HackerEarth Problems/Maximum Product/input.txt", "r", stdin);
    freopen("/ATOM/HackerEarth Problems/Maximum Product/output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        int Q;
        cin >> Q;
        vector<int> A(N);
        for (int i_A = 0; i_A < N; i_A++)
        {
            cin >> A[i_A];
        }
        vector<vector<int>> queries(Q, vector<int>(3));
        for (int i_queries = 0; i_queries < Q; i_queries++)
        {
            for (int j_queries = 0; j_queries < 3; j_queries++)
            {
                cin >> queries[i_queries][j_queries];
            }
        }

        vector<int> out_;
        out_ = maxProduct(N, Q, A, queries);
        cout << out_[0];
        for (int i_out_ = 1; i_out_ < out_.size(); i_out_++)
        {
            cout << "\n"
                 << out_[i_out_];
        }
        cout << "\n";
    }
}