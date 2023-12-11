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
    int t = 3;
    int n = 1e5;
    int q = 1e5;
    int aRange = 1e9;
    srand(time(0));
    std::mt19937 gen(time(0));
    std::uniform_int_distribution<int> dis(1, aRange);
    cout << t << "\n";
    while (t--)
    {
        cout << n << "\n";
        cout << q << "\n";
        for (int i = 0; i < q; i++)
        {
            int l = rand() % n + 1;
            int r = rand() % n + 1;
            int x = dis(gen);
            if (l > r)
                swap(l, r);

            cout << l << " " << r << " " << x << "\n";
        }
    }
}
signed main()
{
    srand(time(0));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    cout << fixed;
#ifndef ONLINE_JUDGE
    // freopen("/ATOM/HackerEarth Problems/Maximum Product/input.txt", "r", stdin);
    freopen("/ATOM/HackerEarth Problems/Minimize Maximum/input.txt", "w", stdout);
#endif
    // #endif
    fun();
    // int t = 1;
    // // cin >> t;
    // while (t--)
    // {
    //     // fun();
    // }
}