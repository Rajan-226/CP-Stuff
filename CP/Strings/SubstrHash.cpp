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
#define mxsize (int)3e5


ll fastexp(ll a, ll n, ll nod = LLONG_MAX) {
    ll ans = 1;
    while (n) {
        if (n & 1)
            ans = (ans * a) % nod;
        a = (a * a) % nod;
        n >>= 1;
    }
    return ans;
}

//l and r should be 0 based
class HashString {
public:
    ll modulo, prime;
    string s;
    vector<ll> prefix;
    vector<ll> modInverse;

    //prime should be greater than largest character of string
    HashString(string& key, ll prime = 31, ll modulo = 1000000009) {
        int n = key.size();
        modInverse = prefix = vector<ll>(n);
        this->modulo = modulo;
        this->prime = prime;
        this->s = key;

        ll hash = 0;
        ll power_prime = 1;

        for (int i = 0; i < key.size(); i++) {
            hash = (hash + (power_prime * (key[i] - 'a' + 1)) % modulo) % modulo;

            prefix[i] = hash;
            modInverse[i] = fastexp(power_prime, modulo - 2, modulo);

            power_prime = (power_prime * prime) % modulo;
        }
    }

    ll getHash(int l, int r) {
        assert(l <= r);
        assert(r < (int) prefix.size());

        ll hash = prefix[r] - ((l == 0) ? 0 : prefix[l - 1]);
        if (hash < 0)
            hash += modulo;

        hash = (hash * modInverse[l]) % modulo;

        return hash;
    }

    bool isEqual(int l1, int r1, int l2, int r2) {
        if ((r1 - l1 + 1) != (r2 - l2 + 1))
            return 0;

        if (getHash(l1, r1) != getHash(l2, r2))
            return 0;


        // Uncomment it if you have n2 time allowed
        // else you can just give it a try
        // for (int i = l1; i <= r1; i++) {
        //     if (s[i] != s[l2++])
        //         return 0;
        // }

        return 1;
    }
};
void fun() {
    string s;
    cin >> s;
    HashString hst(s);
    int q;
    cin >> q;
    while (q--) {
        int type;
        int l, r;
        cin >> type >> l >> r;
        l--; r--;

        //l and r should be 0 based
        if (type == 1)
            cout << hst.getHash(l, r) << "\n";
        else {
            int l2, r2;
            cin >> l2 >> r2;
            l2--; r2--;

            cout << hst.isEqual(l, r, l2, r2) << "\n";
        }
    }

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