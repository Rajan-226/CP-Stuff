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
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
#define mxsize (int)1e6
ll fastexp(ll a,ll n,ll nod){
    if(nod==0)	nod=LLONG_MAX;
    ll lcs=1;
    while(n){
        if(n&1)
            lcs=(lcs*a)%nod;
        a=(a*a)%nod;
        n>>=1;
    }
    return lcs;
}
void fun(){
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    
    cout<<"Length of lcs: ";
    cout<<dp[n][m]<<"\n";

    string lcs;
    while(n>=1&&m>=1){
        if(s[n-1]==t[m-1]){
            lcs+=s[n-1];
            n--;
            m--;
        }
        else if(dp[n][m]==dp[n][m-1])
            m--;
        else
            n--;
    }
    reverse(lcs.begin(),lcs.end());

    cout<<lcs<<"\n";
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
    // cin>>t;
    while(t--){
        fun();
    }
