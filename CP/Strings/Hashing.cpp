#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007
#define pi 3.141592653589
#define nl cout<<"\n"
#define db(x) cout<<x<<" "
#define fi(a,b) for(int i=a;i<b;i++)
#define fj(a,b) for(int j=a;j<b;j++)
#define fk(a,b) for(int k=a;k<b;k++)
#define google(i) cout<<"Case #"<<i<<": "
#define F first
#define S second

int fastexp(int a, int n, int nod = LLONG_MAX) {
    int ans = 1;
    while (n) {
        if (n & 1)
            ans = (ans * a) % nod;
        a = (a * a) % nod;
        n >>= 1;
    }
    return ans;
}
#define mxsize (int)3e5


// Hash = summation of key[i] * prime^i for all i in between 0 to n - 1
ll getHash(string& key, ll prime = 31, ll modulo = 1000000007) {
    ll ans = 0;
    ll power_prime = 1;

    for (int i = 0; i < key.size(); i++) {
        ans = (ans + (power_prime * (key[i] - 'a' + 1)) % modulo) % modulo;
        power_prime = (power_prime * prime) % modulo;
    }

    return ans;
}

void fun() {
    string s;
    cin >> s;
    cout << getHash(s, 31, mod) << "\n";
}
/*

*/
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    cout << fixed;
    //#ifndef ONLINE_JUDGE
    //	freopen("/ATOM/input.txt", "r", stdin);
    //	freopen("/ATOM/output.txt", "w", stdout);
    //#endif
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // google(i);
        fun();
    }
}