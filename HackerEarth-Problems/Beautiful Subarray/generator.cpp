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
#define mxsize (int)1e5
void fun2()
{
    int t = 72;
    int n;

    int aRange = 500;
    int aRange2 = 1e9;
    std::mt19937 gen(time(0));
    std::uniform_int_distribution<int> dis(-aRange, aRange);
    std::uniform_int_distribution<int> dis2(-aRange2, aRange2);

    cout << t + 1 << "\n";
    fk(0, t)
    {
        if (k < 3)
            n = 1e5;
        else
            n = 1e4;
        cout << n << "\n";
        fi(0, n)
        {
            int num = k >= t / 2 ? dis(gen) : dis2(gen);
            cout << num;
            if (i != n - 1)
                cout << " ";
        }
        cout << "\n";
    }
    cout << "1\n-44\n";
}
/*

*/
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    cout << fixed;
    // #ifndef ONLINE_JUDGE
    // freopen("/ATOM/HackerEarth Problems/Beautiful Subarray/input.txt", "r", stdin);
    freopen("/ATOM/HackerEarth Problems/Beautiful Subarray/input.txt", "w", stdout);
    // #endif
    int t = 1;
    // cin >> t;
    while (t--)
    {
        fun2();
    }
}