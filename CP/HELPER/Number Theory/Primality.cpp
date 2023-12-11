#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1000000007
#define pb push_back
#define nl cout<<"\n"
#define db(x) cout<<x<<" "
#define fi(a,b) for(int i=a;i<b;i++)
#define fj(a,b) for(int j=a;j<b;j++)
#define fk(a,b) for(int k=a;k<b;k++)
#define F first
#define S second
#define UM unordered_map<int,int>
#define MP map<int,int>
#define mxsize (int)1e6
// Any prime number can be represented as 6*n+1 or 6*n-1 except 2,3.

// Any two conscecutive numbers are always coprime

bool checkprime(ll n) {
    n = abs(n);
    if (n <= 1)  return 0;
    if (n <= 3)    return 1;
    if (n % 2 == 0 || n % 3 == 0)  return 0;
    for (ll i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)  return 0;

    return 1;
}

void fun() {
    int now = 1e9 + 7;
    int cnt = 10;
    while (cnt) {
        if (checkprime(now)) {
            cout << now << "\n";
            cnt--;
        }
        now++;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/ATOM/input.txt", "r", stdin);
    freopen("/ATOM/output.txt", "w", stdout);
#endif
    int t = 1;
    // cin>>t;
    while (t--) {
        fun();
    }
}