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
#define mxsize (int)1e5+5
vector<ll> w(mxsize, 0), v(mxsize, 0);
int n, capacity;
ll knap1() {
    vector<vector<ll>> dp(n + 1, vector<ll>(capacity + 1, 0));
    fi(1, n + 1) {
        fj(1, capacity + 1) {
            if (w[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][capacity];
}
ll knap2() {
    vector<ll> dp(capacity + 1, 0), last(capacity + 1, 0);
    fi(1, n + 1) {
        fj(1, capacity + 1) {
            if (w[i - 1] <= j)
                dp[j] = max(dp[j], v[i - 1] + last[j - w[i - 1]]);
        }
        last = dp;
    }
    return dp[capacity];
}
ll knap3() {
    vector<ll> dp(capacity + 1, 0);
    fi(1, n + 1) {
        for (int j = capacity; j >= w[i - 1]; j--) {
            dp[j] = max(dp[j], v[i - 1] + dp[j - w[i - 1]]);
        }
    }
    return dp[capacity];
}
int knap4() {
    // change mxsize according to n*val

    // we are going to calculate how less weight can we use to make
    // a particular value as ans
    vector<ll> dp(mxsize + 5, INT_MAX);
    dp[0] = 0;
    fi(0, n) {
        for (int j = mxsize; j >= v[i]; j--) {
            dp[j] = min(dp[j], w[i] + dp[j - v[i]]);
        }
    }
    for (int i = mxsize; i >= 0; i--)  if (dp[i] <= capacity)    return i;
}
void fun() {
    cin >> n >> capacity;
    fi(0, n)		cin >> w[i] >> v[i];
    cout << knap1() << "\n";		// Space : O(n^2) 
    cout << knap2() << "\n";		// Space : O(2*n) 
    cout << knap3() << "\n";		// Space : O(n) 


    cout << knap4() << "\n";	//If Capacity is very high but value is less
                            // when n*val<=1e6
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
    cin >> t;
    while (t--) {
        fun();
    }
}