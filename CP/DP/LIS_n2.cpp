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
#define mxsize (int)1e6

void fun(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int dp[n];
    int len=0,last=-1;
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(dp[i]<dp[j]+1 && a[j]<a[i]){    //See if you want equal elements in subsequence or not
                dp[i]=dp[j]+1;
            }
        }
        
        if(len<dp[i]){
            len=dp[i];
            last=i;
        }
    }
    
    vector<int> lis;
    lis.push_back(a[last]);
    for(int i=last;i>=0;i--){
        if(dp[i]+1==dp[last] && a[i]<a[last]){
            lis.push_back(a[i]);
            last=i;
        }
    }
    reverse(lis.begin(),lis.end());

    cout<<len<<"\n";
    for(auto i:lis)    db(i);  
    nl;  
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