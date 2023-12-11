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
ll convert(string str, ll base) //It will convert number of base b to base 10
{ 
    ll num = 0;
    ll p = 1;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        num += (str[i] - '0') * p;
        p = p * base;
    }
    return num;
}
// Negative numbers mein shyd  gdbd ho skti hai
string decimal_to_binary(ll n)
{
    string s;
    while (n)
    {
        if (n % 2)
            s += '1';
        else
            s += '0';
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}
ll binary_to_decimal(string s)
{
    ll n = 0, c = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            n += 1ll << c;
        }
        c++;
    }
    return n;
}
void fun()
{
    int n;
    cin >> n;
    cout << decimal_to_binary(n);
    nl;
    string s;
    cin >> s;
    cout << binary_to_decimal(s);
    nl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/ATOM/input.txt", "r", stdin);
    freopen("/ATOM/output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        fun();
    }
}