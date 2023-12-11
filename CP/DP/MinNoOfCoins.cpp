#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1000000007
#define pb push_back
#define nl cout<<"\n"
#define db(sum) cout<<sum<<" "
#define fi(a,b) for(int i=a;i<b;i++)
#define fj(a,b) for(int j=a;j<b;j++)
#define fk(a,b) for(int k=a;k<b;k++)
#define F first
#define S second
#define UM unordered_map<int,int>
#define MP map<int,int>
#define mxsize (int)1e6
// Minimum number of coins required for attaining a particular sum

void fun(){
    ll n,sum;
    cin>>n>>sum;
    ll a[n];
    fi(0,n) cin>>a[i];

    ll dp[sum+1];
    dp[0]=0;
    fi(1,sum+1)   dp[i]=INT_MAX;

    fi(1,sum+1){
        fj(0,n){                                                            // Try every coin that has smaller value than i
            if(i>=a[j])                                          //check if i(sum required) is greater than coin value
                dp[i]=min(dp[i],dp[i-a[j]]+1);
        }
    }

    if(dp[sum]==INT_MAX)  dp[sum]=-1;       //not possible
    cout<<dp[sum];

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("/ATOM/input.txt", "r", stdin);
        freopen("/ATOM/output.txt", "w", stdout);
    #endif
    int t=1;
    cin>>t;
    while(t--){
        fun();
    }
}