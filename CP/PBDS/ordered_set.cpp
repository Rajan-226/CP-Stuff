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

#define vvl vector<vector<ll>>
#define vl vector<ll>
#define pl pair<ll,ll>
#define ppl pair<ll,pair<ll,ll>>
#define mxsize (int)1e6+5

/*
Alternative with lesser time :

https://www.geeksforgeeks.org/order-statistic-tree-using-fenwick-tree-bit/
*/



#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;

template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// st.find_by_order(k);     it returns an iterator to the k-th largest element (counting from zero based)
// k is 0 based

// st.order_of_key(num);     it returns count of numbers strictly less than num

// use multiset if you want same element mutiple times in the set

void fun() {
    ordered_multiset<int> o;
    o.insert(5);
    o.insert(5);
    o.insert(10);
    cout << o.order_of_key(6) << "\n";
    cout << o.order_of_key(5) << "\n";  //because there is no element strictly less than 5
    o.erase(o.find(5));
    cout << o.order_of_key(6) << "\n\n";        //This is unexpected in a multiset

    cout << *o.find_by_order(1) << "\n";
    o.erase(o.find_by_order(0));
    cout << o.order_of_key(6) << "\n\n";    //This can be helpful in this case      



    ordered_set<int> s;
    s.insert(5);
    s.insert(5);
    s.insert(10);
    cout << s.order_of_key(6) << "\n";
    cout << *s.find_by_order(1) << "\n";

    s.erase(s.find(5));
    cout << s.order_of_key(6) << "\n";

    /*
    
    2
    0
    2

    5
    1

    1
    10
    0

    */
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(20);
    cout << fixed;
    int t = 1;
    // cin>>t;
    while (t--) {
        fun();
    }
}