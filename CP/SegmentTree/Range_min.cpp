#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1000000007
#define nl cout << "\n"
#define db(x) cout << x << " "
#define fi(a, b) for (int i = a; i < b; i++)
#define fj(a, b) for (int j = a; j < b; j++)
#define fk(a, b) for (int k = a; k < b; k++)
#define F first
#define S second
#define UM unordered_map<int, int>
#define MP map<int, int>
#define int long long


class SegmentTree {
// 0 based indexing while querying
// WARN: Check if you want long long instead of int as sum can be bigger than size of int
public:
    // pass the 0 based indexed array
    SegmentTree(vector<int> arr) {
        _n = arr.size();        //WARN: Your array should not have unnecessary 0s in the end
        tree = vector<int>(4 * _n, 0);
        build_tree(1, 0, _n - 1, arr);
    }

    int query(int l, int r) {
        if (l < 0 || r >= _n || l > r) {
            return 0;   // WARN: Check this case
        }
        return query(1, 0, _n - 1, l, r);
    }

    void update(int index, int value) {
        if (index < 0 || index >= _n) {
            return ;    // WARN: Check this case
        }
        update(1, 0, _n - 1, index, value);
    }

private:
    vector<int> tree;
    int _n;

    int operation(int x, int y) {
        return min(x, y)
    }

    int query(int si, int ss, int se, int qa, int qb) {
        assert(qa <= qb);

        if (ss > qb || se < qa)
            return 0; // Base case: outside range, return neutral element

        if (ss >= qa && se <= qb)
            return tree[si];

        int mid = (ss + se) / 2;
        int left = query(2 * si, ss, mid, qa, qb);
        int right = query(2 * si + 1, mid + 1, se, qa, qb);

        return operation(left, right);
    }

    void update(int si, int ss, int se, int pos, int val) {
        if (ss == se) {
            tree[si] = val;
            return;
        }

        int mid = (ss + se) / 2;

        if (pos <= mid)
            update(2 * si, ss, mid, pos, val);
        else
            update(2 * si + 1, mid + 1, se, pos, val);

        tree[si] = operation(tree[2 * si], tree[2 * si + 1]);
    }

    void build_tree(int si, int ss, int se, vector<int> &arr) {
        if (ss == se) {
            tree[si] = arr[ss];
            return;
        }
        int mid = (ss + se) / 2;
        build_tree(2 * si, ss, mid, arr);
        build_tree(2 * si + 1, mid + 1, se, arr);

        tree[si] = operation(tree[2 * si], tree[2 * si + 1]);
    }
};


void fun()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    fi(0, n) cin >> arr[i];
    SegmentTree s(arr, n);

    ll q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << s.query(x, y);
    }
}
/*
si-segment index
                      1                         1
            2                  3                2,3
        4        5          6         7         4,5,6,7    
     8    9   10   11     12  13    14  15      8,9,10,11,12,13,14,15

    You can observe left child of every parent is represented by 2*parent
    and right child of every parent is 2*parent+1   
*/
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/ATOM/input.txt", "r", stdin);
    freopen("/ATOM/output.txt", "w", stdout);
#endif
    int t = 1;
    // cin>>t;
    while (t--)
    {
        fun();
    }
}