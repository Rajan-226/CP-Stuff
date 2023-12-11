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

//https://leetcode.com/problems/longest-happy-prefix/

vector<int> findLPS(string& s) {
    int n = s.size();
    vector<int> lps(n);
    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = lps[j - 1];     //because now we need longest proper prefix of previous suffix
            //Consider the example "ababe......ababc", i is index of 'c', len==4. The longest prefix suffix is "abab",
            //when pat[i]!=pat[len], we get new prefix "ababe" and suffix "ababc", which are not equal. 
            //This means we can't increment length of lps based on current lps "abab" with len==4. We may want to increment it based on
            //the longest prefix suffix with length < len==4, which by definition is lps of "abab". So we set len to lps[len-1],
            //which is 2, now the lps is "ab". Then check pat[i]==pat[len] again due to the while loop, which is also the reason
            //why we do not increment i here. The iteration of i terminate until len==0 (didn't find lps ends with pat[i]) or found
            //a lps ends with pat[i].
        }
        lps[i] = j + (s[i]==s[j]);
    }
    return lps;
}


void fun() {
    string s;
    cin >> s;

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