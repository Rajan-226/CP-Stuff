#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007
#define pi 3.141592653589
#define nl cout << "\n"
#define db(x) cout << x << " "
#define fi(a, b) for (int i = a; i < b; i++)
#define fj(a, b) for (int j = a; j < b; j++)
#define fk(a, b) for (int k = a; k < b; k++)
#define F first
#define S second

int fastexp(int a, int n, int nod = LLONG_MAX)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)
            ans = (ans * a) % nod;
        a = (a * a) % nod;
        n >>= 1;
    }
    return ans;
}
#define mxsize (int)3e5

void fun()
{
    int n;
    cin >> n;
    int a[n];
    fi(0, n) cin >> a[i];
    int ans = -1e18;
    fi(0, n)
    {
        int now = 1, sum = 0;
        fj(i, n)
        {
            sum += now * a[j];
            ans = max(ans, sum);
            if (now == -1)
                now = 1;
            else
                now = -1;
        }
    }
    cout << ans << "\n";
}
/*

*/
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    cout << fixed;
#ifndef ONLINE_JUDGE
    freopen("/ATOM/HackerEarth Problems/Beautiful Subarray/input.txt", "r", stdin);
    freopen("/ATOM/HackerEarth Problems/Beautiful Subarray/output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        fun();
    }
}