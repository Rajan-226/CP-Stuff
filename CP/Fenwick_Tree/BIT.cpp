#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define nl cout << "\n"
#define db(x) cout << x << " "
#define fi(a, b) for (int i = a; i < b; i++)
#define fj(a, b) for (int j = a; j < b; j++)
#define fk(a, b) for (int k = a; k < b; k++)
#define F first
#define S second
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (auto &v : vec)
        is >> v;
    return is;
}
#define mxsize (int)1e6
ll fastexp(ll a, ll n, ll nod) {
    if (nod == 0)
        nod = LLONG_MAX;
    ll ans = 1;
    while (n) {
        if (n & 1)
            ans = (ans * a) % nod;
        a = (a * a) % nod;
        n >>= 1;
    }
    return ans;
}
/*
 *
 * https://www.youtube.com/watch?v=v_wj_mOAlig&ab_channel=JAlgs
 *
 * x & (-x) extracts rightmost set bit of a number
 * x - (x & (-x)) removes the rightmost set bit
 *
 *
 */
class BIT {
private:
    // Pass everything as 1 based
    vector<ll> bit;
    int n;

    int getLSB(int x) {
        return x & (-x);
    }

public:
    BIT(vector<ll> a) {
        //pass 0 based array
        n = a.size();
        bit = vector<ll>(n + 1, 0);
        for (int i = 1; i <= n; i++)
            add(i, a[i - 1]);       
    }

    BIT(int n) {
        this->n = n;
        bit = vector<ll>(n + 1, 0);
    }

    void add(int ind, ll val) {
        ind++;
        while (ind <= n) {
            bit[ind] += val;
            ind += getLSB(ind);
        }
    }

    void changeAtTo(int ind, ll val) {
        add(ind, val - elementAt(ind));
    }

    ll prefsum(int ind) {
        ll ans = 0;
        ind++;
        while (ind > 0) {
            ans += bit[ind];
            ind -= getLSB(ind);
        }
        return ans;
    }

    ll rangesum(int from, int to) {
        return prefsum(to) - prefsum(from - 1);
    }

    ll elementAt(int ind) {
        return prefsum(ind) - prefsum(ind - 1);
    }
};
/*
const int N  = 1001;        //max value of ai
int lsb(int n) { return (n & -n);}
void update(vector<int> & bit, int index, int val) {
    for (int i = index; i < bit.size(); i += lsb(i)) bit[i] += val;
}
int query(vector<int> & bit, int index) {
    int ans = 0;
    for (int i = index; i > 0; i -= lsb(i))ans += bit[i];
    return ans;
}
int main(){
    int n ;
    cin >> n ;
    vector<int> arr(n + 1);
    vector<vector<int>> fenwick(N , vector<int>(n + 1 , 0));
    for (int i = 1 ; i <= n ; i++)
        cin >> arr[i];

    for (int i = 1; i <= n ; i++) {
        update(fenwick[arr[i]] , i , 1);
    }

    int q;
    cin>>q;
    while (q--) {
        char c ; int x , y ;
        cin >> c >> x >> y ;

        if (c == '?') {
            int req;
            cin>>req;
            int freq = query(fenwick[req] , y) - query(fenwick[req] , x - 1);

            cout << freq << endl;
        }
        else if (c == '*') {
            int curr = arr[x];
            int newVal =  y ;

            update(fenwick[curr] , x , -1);
            update(fenwick[newVal], x , 1);

            arr[x] = newVal ;
        }
    }
}

*/
void fun() {
    vector<ll> arr{1, 7, 3, 0, 5, 8, 3, 2, 6, 2, 1, 1, 4, 5};
    int length = arr.size();

    BIT bit(arr);

    db(bit.prefsum(6));

    bit.add(2, -10);

    db(bit.rangesum(1, 3));

    bit.changeAtTo(2, 10);

    db(bit.elementAt(2));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("/ATOM/input.txt", "r", stdin);
    //     freopen("/ATOM/output.txt", "w", stdout);
    // #endif
    int t = 1;
    // cin >> t;
    while (t--) {
        fun();
    }
}