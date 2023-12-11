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
    int t = 10;
    int N = 1e5;
    int M = 1e5;
    srand(time(0));
    cout << t << "\n";
    while (t--)
    {
        int n = rand() % N + 1;

        int rangeL = rand() % 26;
        int rangeR = rand() % 26;
        if (rangeL > rangeR)
            swap(rangeL, rangeR);
        while (rangeR - rangeL + 1 < 6)
        {
            if (rangeR < 25)
                rangeR++;
            else
                rangeL--;
        }

        n = N;
        cout << n << "\n";
        fi(0, n)
        {
            char c = 'a' + rangeL + rand() % (rangeR - rangeL + 1);
            cout << c;
        }
        cout << "\n";
        int m = rand() % M + 1;
        m = M;
        cout << m << "\n";
        fi(0, m)
        {
            char c = 'a' + rangeL + rand() % (rangeR - rangeL + 1);
            cout << c;
        }
        cout << "\n";
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
    // freopen("/ATOM/HackerEarth Problems/Longest Palindromic String/input.txt", "r", stdin);
    freopen("/ATOM/HackerEarth Problems/Longest Palindromic String/input.txt", "w", stdout);
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