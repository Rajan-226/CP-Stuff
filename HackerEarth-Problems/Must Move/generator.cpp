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
/*
1 2 3 4 5 6



*/
void fun()
{
    int t = 5;
    int n = 1000;
    int m = 1000;
    int aRange = 1e9;
    cout << t << "\n";
    std::mt19937 gen(time(0));
    std::uniform_int_distribution<int> dis(1, aRange);
    while (t--)
    {
        // n = rand() % n + 1;
        // m = rand() % m + 1;
        cout << n << "\n"
             << m << "\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int val = dis(gen);
                if (t != 1)
                {
                    if (i == 0 && j <= 1)
                        val = rand() % 2;
                    if (j == 0 && i <= 1)
                        val = rand() % 2;
                }
                if (i == 0 && j == 0)
                    val = 0;
                cout << val;
                if (j != m - 1)
                    cout << " ";
            }
            cout << "\n";
        }
    }
}
/*
Given a matrix of N*M.
matrix[i][j] represents the minimum time at which you can enter cell (i,j)
Initially you are at (1,1) at 0 second by moving in any 4 directions from a cell.
There is a condition that at each second, you have to move to some cell.
Print the minimum time to reach (n,m) or -1 if you cannot reach (n,m)


//parity same -
//2 se 4 pr jaana h toh, 3 on back, 4 on forth, toh 5 pr jaa paaega
//1 se 3 pr jaana h toh, 2 on back, 3 on forth, toh 4 pr jaa paaega

//parity different -
//2 se 5 jaana toh, 3 on back, 4 on forth, 5 se sidha next cell
//same for odd

*/
signed main()
{
    srand(time(0));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    cout << fixed;
    // #ifndef ONLINE_JUDGE
    // freopen("/ATOM/input.txt", "r", stdin);
    freopen("/ATOM/input.txt", "w", stdout);
    // #endif
    int t = 1;
    // cin >> t;
    while (t--)
    {
        // fun();
    }
}