#include <bits/stdc++.h>
using namespace std;
int give(int n)
{
    while (n / 10)
        n /= 10;
    return n;
}
long long countPairs(int N, vector<int> A)
{
    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int last = A[j] % 10;
            int front = give(A[i]);
            if (__gcd(front, last) == 1)
                ans++;
        }
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