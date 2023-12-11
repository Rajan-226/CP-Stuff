#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define nl cout<<"\n"
#define db(x) cout<<x<<" "
#define fi(a,b) for(int i=a;i<b;i++)
#define fj(a,b) for(int j=a;j<b;j++)
#define fk(a,b) for(int k=a;k<b;k++)
#define F first
#define S second
template <typename T> istream& operator>>(istream& is, vector<T>& vec) { for (auto& v : vec) is >> v; return is; }
#define mxsize (int)1e6
ll fastexp(ll a, ll n, ll nod) {
    if (nod == 0)	nod = LLONG_MAX;
    ll ans = 1;
    while (n) {
        if (n & 1)
            ans = (ans * a) % nod;
        a = (a * a) % nod;
        n >>= 1;
    }
    return ans;
}
int Lis(vector<int>& a) {
    int n = a.size();
    vector<int> sq;
    sq.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (sq.back() < a[i]) {         // 1 
            sq.push_back(a[i]);
        } else {
            int ind = lower_bound(sq.begin(), sq.end(), a[i]) - sq.begin();       //2
            sq[ind] = a[i];
        }
    }
    // if u want equal elements also, then use equal sign
    // at 1 and upper_bound at 2

    return (int) sq.size();
}
void fun() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << Lis(a) << "\n";

}
// 1 5 16 17 15 18
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/ATOM/input.txt", "r", stdin);
    freopen("/ATOM/output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--) {
        fun();
    }
}