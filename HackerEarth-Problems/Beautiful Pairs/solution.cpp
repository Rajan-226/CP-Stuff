#include <bits/stdc++.h>
using namespace std;

long long countPairs(int N, vector<int> A)
{
    long long ans = 0;
    vector<int> mp(10);
    for (int i = N - 1; i >= 0; i--)
    {
        int last = A[i] % 10;
        while (A[i] / 10)
            A[i] /= 10;
        for (int j = 0; j < 10; j++)
            if (__gcd(A[i], j) == 1)
                ans += mp[j];
        mp[last]++;
    }
    return ans;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("/ATOM/HackerEarth Problems/Beautiful Pairs/input.txt", "r", stdin);
    freopen("/ATOM/HackerEarth Problems/Beautiful Pairs/output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i_A = 0; i_A < N; i_A++)
        {
            cin >> A[i_A];
        }

        long long out_;
        out_ = countPairs(N, A);
        cout << out_;
        cout << "\n";
    }
}