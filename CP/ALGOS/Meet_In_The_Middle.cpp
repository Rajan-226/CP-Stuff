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
#define F first
#define S second
ll fastexp(ll a,ll n,ll nod=LLONG_MAX){
    ll ans=1;
    while(n){
        if(n&1)
            ans=(ans*a)%nod;
        a=(a*a)%nod;
        n>>=1;
    }
    return ans;
}
#define mxsize (int)3e5
//https://www.geeksforgeeks.org/meet-in-the-middle/
//Given a array of n integers where n <= 40.
//determine the maximum sum subset having closest sum to S 
//and return abs(goal-sum)
void help(vector<long long>& x,vector<int>& nums,int ind,int n,long long sum){
    if(ind==n){
        x.push_back(sum);
        return ;
    }
    help(x,nums,ind+1,n,sum+nums[ind]);
    help(x,nums,ind+1,n,sum);
}
int minAbsDifference(vector<int>& nums, int goal) {
    vector<long long> x;
    vector<long long> y;
    int n=nums.size();
    help(x,nums,0,n/2,0);
    help(y,nums,n/2,n,0);
    int nx=x.size(),ny=y.size();        sort(y.begin(),y.end());
    int ans=INT_MAX;
    for(int i=0;i<nx;i++){
        int ind=lower_bound(y.begin(),y.end(),goal-x[i])-y.begin();
        if(ind>0){
            ans=min(ans,(int)abs(goal-y[ind-1]-x[i]));
        }
        if(ind<ny){
            ans=min(ans,(int)abs(goal-y[ind]-x[i]));
        }
    }
    
    return ans;
}
void fun(){
    
}
/*

*/
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    cout<<fixed;
    //#ifndef ONLINE_JUDGE
    //	freopen("/ATOM/input.txt", "r", stdin);
    //	freopen("/ATOM/output.txt", "w", stdout);
    //#endif
    int t=1;
    cin>>t;
    while(t--){
        fun();
    }
}