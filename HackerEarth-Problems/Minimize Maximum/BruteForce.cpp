#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> maxProduct(int N, int Q, vector<int> A, vector<vector<int>> queries)
{
    // Write your code here
    vector<int> ans;
    for (auto v : queries)
    {
        int maxp = LLONG_MIN;
        int l = v[1], r = v[2];
        l--;r--;
        if (v[0] == 1)
        {
            for (int i = l; i <= r; i++)
            {
                for (int j = i + 1; j <= r; j++)
                {
                    maxp = max(maxp, A[i] * A[j]);
                }
            }
        }
        else
        {
            for (int i = l; i <= r; i++)
            {
                for (int j = i + 1; j <= r; j++)
                {
                    for (int k = j + 1; k <= r; k++)
                    {
                        maxp = max(maxp, A[i] * A[j] * A[k]);
                    }
                }
            }
        }
        ans.push_back(maxp);
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