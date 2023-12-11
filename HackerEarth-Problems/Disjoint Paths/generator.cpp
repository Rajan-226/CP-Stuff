#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#include </ATOM/HackerEarth Problems/Disjoint Paths/treegenerator.h>
using namespace tree_generator_by_ouuan;
using namespace std;
#define ll long longp
// #define int long long
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
int weights;
void myOutputEdge(ostream &os, int u, int pa)
{
    os << u + 1 << ' ' << pa + 1 << ' ' << randint(1, weights) << "\n";
}
void fun()
{
    int T = 10;
    int N = 1e5;
    weights = 1e9;
    outputEdge = myOutputEdge;
    cout<<T<<"\n";
    fk(0, T)
    {
        cout << N << "\n";
        Tree t(N);
        cout<<t;
        if(k>=5) weights=1e3;
    }
}
/*

*/
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.precision(20);
    // cout << fixed;
    //#ifndef ONLINE_JUDGE
    //	freopen("/ATOM/input.txt", "r", stdin);
    freopen("/ATOM/HackerEarth Problems/Disjoint Paths/input.txt", "w", stdout);

    //#endif
    int t = 1;
    // cin >> t;
    while (t--)
    {
        fun();
    }
}