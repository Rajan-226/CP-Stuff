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
int n;
int a[mxsize];
bool fun(bool ok)
{
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
    int ans2 = ans;
    sumN = sumP = 0;
    ans = 0;
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
    if (ok)
        return ans > ans2;
    return ans2 > ans;
}
void fun2()
{
    int t = 10;
    cout << t << "\n";

    int aRange = 1e6;

    std::mt19937 gen(time(0));
    std::uniform_int_distribution<int> dis(-aRange, aRange);
    while (t)
    {
        n = 1e5;
        if (t <= 8)
        {
            cout << n << "\n";
            t--;
        }
        fi(0, n)
        {
            // if (t == 2)
            //     a[i] = aRange;
            // else
                a[i] = dis(gen);
            if (t <= 8)
            {
                cout << a[i];
                if (i != n - 1)
                    cout << " ";
            }
        }
        if (t == 10 && fun(1))
        {
            cout << n << "\n";

            fi(0, n)
            {
                cout << a[i];
                if (i != n - 1)
                    cout << " ";
            }

            cout << "\n";
            t--;
        }
        else if (t == 9 && fun(0))
        {
            cout << n << "\n";

            fi(0, n)
            {
                cout << a[i];
                if (i != n - 1)
                    cout << " ";
            }

            cout << "\n";
            t--;
        }
        if (t < 8)
            cout << "\n";
    }
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
    // freopen("/ATOM/.txt", "r", stdin);
    freopen("/ATOM/input.txt", "w", stdout);
    // #endif
    int t = 1;
    // cin >> t;
    while (t--)
    {
        fun2();
    }
}