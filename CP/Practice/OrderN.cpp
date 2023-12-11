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
    int l = 0, r = 0;
    while (r <= n) {

        while (l < r && (a[r] - a[l]) > 200) {
            int dif = a[r] - a[l];
            int value = (200 - dif) * (200 - dif);
            dp[r] = min(dp[r], dp[l] + value);

            l++;
        }

        if (l < r) {
            int dif = a[r] - a[l];
            int value = (200 - dif) * (200 - dif);
            dp[r] = min(dp[r], dp[l] + value);
        }

        //moving back to maintain gap of 200 for next element also
        if (l > 0)
            l--;
            
        r++;
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