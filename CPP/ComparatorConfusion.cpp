// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007
#define pi 3.141592653589
#define nl cout<<"\n"
#define db(x) cout<<x<<" "
#define aaja(x) cout<<"Present "<<x<<"\n"
#define fi(a,b) for(int i=a;i<b;i++)
#define fj(a,b) for(int j=a;j<b;j++)
#define fk(a,b) for(int k=a;k<b;k++)
#define google(i) cout<<"CASE #"<<i<<": "
#define F first
#define S second

int fastexp(ll a, ll n) {
    ll aPowerN = 1;
    while (n) {
        if (n & 1)
            aPowerN = (aPowerN * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return (aPowerN + mod) % mod;
}
#define mxsize (int)300005 //3e5+5


struct comp2 {
    //true gives priority to 2nd parameter
    bool operator()(int a, int b) {
        return b > a;
    }
};

//true gives priority to 1st parameter
bool comp(int x, int y) {
    return x < y;
}

void fun() {
    vector<int> v = { 1,2,3 };
    priority_queue<int, vector<int>, comp2> q;
    sort(v.begin(), v.end(), comp);
    fi(0, 3) cout << v[i] << " "; nl;
    q.push(1);
    q.push(2);
    q.push(3);
    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
}
/**
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
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // google(i);
        fun();
    }
}