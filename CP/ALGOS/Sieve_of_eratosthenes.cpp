#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1000000007
#define pb push_back
#define nl cout << "\n"
#define db(x) cout << x << " "
#define fi(a, b) for (int i = a; i < b; i++)
#define fj(a, b) for (int j = a; j < b; j++)
#define fk(a, b) for (int k = a; k < b; k++)
#define F first
#define S second
#define UM unordered_map<int, int>
#define MP map<int, int>
#define mxsize (int)1e6
// Print all primes upto n in nlog(logn) timecomplexity

// Create a boolean array "prime[0..n]" and initialize
// all numbers in it as false. A value in prime[i] will
// be marked as true if i is not a prime.

// Update all multiples of i greater than or equal to the square of it numbers which are multiple of p and are less than
// p^2 are already been marked.

//if a number i is a prime then a[i] will be 0.

#define mxsize (int)1e6

vector<bool> is_prime(mxsize + 5, 0);
vector<ll> numberOfPrimeUpto(mxsize + 5, 0);
vector<int> primes;
void sieve(int n)
{
    is_prime[1] = 1;
    int cnt=0;
    for (ll i = 2; i * i <= n; i++)
    {
        if (is_prime[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = 1;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        numberOfPrimeUpto[i] = numberOfPrimeUpto[i - 1];
        if (is_prime[i] == 0)
        {
            primes.push_back(i);
            numberOfPrimeUpto[i] += 1;
            // cout<<i<<" ";
        }
    }
    // cout<<primes.size()<<"\n";          // There are 78,499 primes upto 1e6
}
void fun()
{
}

//Two conscecutive numbers are always coprime

//Number of divisors of a number is multiplication
//of power+1 of primes divisors of that number
//200=(2^(3))*(5^(2) )     //no. of divisors=(3+1)*(2+1)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/ATOM/input.txt", "r", stdin);
    freopen("/ATOM/output.txt", "w", stdout);
#endif

    sieve(mxsize);
    int t;
    cin >> t;
    while (t--)
    {
        fun();
    }
}
