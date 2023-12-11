#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007
#define pi 3.141592653589
#define nl cout << "\n"
#define db(x) cout << x << " "
#define aaja(x) cout << "Present " << x << "\n"
#define fi(a, b) for (int i = a; i < b; i++)
#define fj(a, b) for (int j = a; j < b; j++)
#define fk(a, b) for (int k = a; k < b; k++)
#define google(i) cout << "CASE #" << i << ": "
#define F first
#define S second

int fastexp(ll a, ll n)
{
    ll aPowerN = 1;
    while (n)
    {
        if (n & 1)
            aPowerN = (aPowerN * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return (aPowerN + mod) % mod;
}
#define mxsize (int)300005 // 3e5+5

struct Node
{
    vector<int> child;
    vector<int> endIndex;

    Node(){
        child = vector<int>(32);
    }
};


class Trie{
public:

}



void fun()
{
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }






}
/**
 *
 */
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //#ifndef ONLINE_JUDGE
    //	freopen("/ATOM/input.txt", "r", stdin);
    //	freopen("/ATOM/output.txt", "w", stdout);
    //#endif
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // google(i);
        fun();
    }
}