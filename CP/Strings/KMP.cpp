// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
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
#define google(i) cout << "Case #" << i << ": "
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

// lps[i] -> longest prefix length which is matching with the suffix ending at index i
// Basically, we are just trying to avoid rematching pattern and reiterating i
// TC: O(N+M)

vector<int> findLPS(string s) {
    int n = s.size();
    vector<int> lps(n);
    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = lps[j - 1]; // because now we need longest proper prefix of previous suffix
        }
        lps[i] = j + (s[i] == s[j]);
    }
    return lps;
}

bool isSubstr(string &s, string &pat) {
    string now = pat + "#" + s;
    int n = pat.size();
    vector<int> lps(n + 1);
    for (int i = 1; i < now.size(); i++) {
        int j = lps[i - 1];
        while (j > 0 && now[i] != now[j]) {
            j = lps[j - 1]; // because now we need longest proper prefix of previous suffix
        }
        lps[i] = j + (now[i] == now[j]);
        if (i > n && lps[i] == n)
            return true;
    }
    return false;
}

void fun() {
    string pat, s;
    cin >> pat >> s;
    vector<int> got = findLPS(pat + "%" + s);
    int ans = 0;
    for (int i = pat.size() + 1; i < got.size(); i++) {
        if (got[i] == pat.size())
            ans++;
    }
    // ans = number of times pat exist in string s
    cout << isSubstr(s, pat) << "\n";
    cout << ans << "\n";
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