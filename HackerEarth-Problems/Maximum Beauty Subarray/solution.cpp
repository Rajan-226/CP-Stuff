#include <bits/stdc++.h>
using namespace std;
#define int long long
void fun()
{
    int n;
    cin >> n;
    assert(1 <= n && n <= (int)1e5);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        assert((int)-1e6 <= a[i] && a[i] <= (int)1e6);
    }
    int ans = 0;
    int sumP = 0, sumN = 0;
    int maxPositive = a[0], maxNegative = a[0];
    for (int i = 0; i < n; i++)
    {
        if (sumN > 0)
        {
            maxNegative = a[i];
            sumN = 0;
        }
        if (sumP < 0)
        {
            maxPositive = a[i];
            sumP = 0;
        }
        sumP += a[i];
        sumN += a[i];
        maxPositive = max(maxPositive, a[i]);
        maxNegative = min(maxNegative, a[i]);
        ans = max(ans, maxPositive * sumP);
        ans = max(ans, maxNegative * sumN);
    }
    sumN = sumP = 0;
    maxPositive = maxNegative = a[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        if (sumN > 0)
        {
            maxNegative = a[i];
            sumN = 0;
        }
        if (sumP < 0)
        {
            maxPositive = a[i];
            sumP = 0;
        }
        sumP += a[i];
        sumN += a[i];
        maxPositive = max(maxPositive, a[i]);
        maxNegative = min(maxNegative, a[i]);
        ans = max(ans, maxPositive * sumP);
        ans = max(ans, maxNegative * sumN);
    }
    cout << ans << '\n';
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/ATOM/input.txt", "r", stdin);
    freopen("/ATOM/output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    assert(1 <= t && t <= 10);
    while (t--)
    {
        fun();
    }
}