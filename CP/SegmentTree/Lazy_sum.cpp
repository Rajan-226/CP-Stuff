#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pi 3.141592653589
#define nl cout<<"\n"
#define db(x) cout<<x<<" "
#define fi(a,b) for(int i=a;i<b;i++)
#define fj(a,b) for(int j=a;j<b;j++)
#define fk(a,b) for(int k=a;k<b;k++)
#define F first
#define S second
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
#define mxsize (int)2e5
ll input[mxsize];
ll tree[4 * mxsize], lazy[4 * mxsize];

void build(int si, int ss, int se) {
    if (ss == se) {
        tree[si] = input[ss];
        return;
    }
    int mid = (ss + se) / 2;
    build(2 * si, ss, mid);
    build(2 * si + 1, mid + 1, se);

    tree[si] = tree[2 * si] + tree[2 * si + 1];
}

ll query(int si, int ss, int se, int qs, int qe) {
    if (lazy[si] != 0) {
        tree[si] += (se - ss + 1) * lazy[si];

        lazy[2 * si] += lazy[si];
        lazy[2 * si + 1] += lazy[si];
        lazy[si] = 0;
    }
    if (qe<ss || qs>se)   return 0;
    if (ss >= qs && se <= qe)  return tree[si];
    int mid = (ss + se) / 2;
    return query(2 * si, ss, mid, qs, qe) + query(2 * si + 1, mid + 1, se, qs, qe);
}

void update_range(int si, int ss, int se, int qs, int qe, int val) {
    if (lazy[si] != 0) {
        tree[si] += (se - ss + 1) * lazy[si];

        lazy[2 * si] += lazy[si];
        lazy[2 * si + 1] += lazy[si];
        lazy[si] = 0;
    }
    if (qe<ss || qs>se)   return;
    if (ss >= qs && se <= qe) {
        tree[si] += (se - ss + 1) * val;
        if (ss != se) {
            lazy[2 * si] += val;
            lazy[2 * si + 1] += val;
        }
        return;
    }
    int mid = (ss + se) / 2;
    update_range(2 * si, ss, mid, qs, qe, val);
    update_range(2 * si + 1, mid + 1, se, qs, qe, val);

    tree[si] = tree[2 * si] + tree[2 * si + 1];
}
void print(int si, int ss, int se) {
    cout << ss << " " << se << " " << tree[si] << "\n";
    if (ss == se)  return;
    int mid = (ss + se) / 2;
    print(2 * si, ss, mid);
    print(2 * si + 1, mid + 1, se);
}
void fun() {
    // Remember input is 1 based
    int n;
    cin >> n;
    fi(1, n + 1)     cin >> input[i];
    fi(0, 4 * n + 1) {
        tree[i] = lazy[i] = 0;
    }
    build(1, 1, n);
    // print(1,1,n);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        int start, end;
        cin >> start >> end;    //range should be 1 based
        if (type == 1)     cout << query(1, 1, n, start, end) << "\n";
        else {
            ll value;
            cin >> value;
            update_range(1, 1, n, start, end, value);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(20);
    cout << fixed;
    // #ifndef ONLINE_JUDGE
    //     freopen("/ATOM/input.txt", "r", stdin);
    //     freopen("/ATOM/output.txt", "w", stdout);
    // #endif
    int t = 1;
    cin >> t;
    while (t--) {
        fun();
    }
}