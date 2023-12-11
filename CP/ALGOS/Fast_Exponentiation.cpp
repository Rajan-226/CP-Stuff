#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// To compute (a to power n)%mod in O(logn)

//we are just representing n in form of binary 

/*
 *
 * a^10 
 * 
 * write 10 in binary which is 1010
 * 
 * so, we need to calculate (a^8)*(a^2)
 * 
 * so whenever there will be 1 in binary form of power, we will multiply the current power 
 * 
 * 
 */


ll fastexp(ll a,ll n){
    ll ans=1;
    while(n){
        if(n&1)
            ans=(ans*a)%mod;
        a=(a*a)%mod;
        n/=2;
    }
    return ans;
}

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   #ifndef ONLINE_JUDGE
      freopen("/ATOM/input.txt", "r", stdin);
      freopen("/ATOM/output.txt", "w", stdout);
   #endif

   cout<<fastexp(4,3);
}