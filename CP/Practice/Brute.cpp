#include <bits/stdc++.h>
using namespace std;
#define int long long

void fun() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int dif = a[i] - a[j];
            int value = (200 - dif) * (200 - dif);

            dp[i] = min(dp[i], dp[j] + value);
        }
    }

    cout << dp[n] << "\n";

}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // google(i);
        fun();
    }
}