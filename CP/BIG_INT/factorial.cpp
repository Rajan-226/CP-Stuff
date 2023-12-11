#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1000000007
#define nl cout<<"\n"
#define db(x) cout<<x<<" "
#define fi(a,b) for(int i=a;i<b;i++)
#define fj(a,b) for(int j=a;j<b;j++)
#define fk(a,b) for(int k=a;k<b;k++)
#define F first
#define S second
#define pb push_back
#define UM unordered_map<int,int>
void mul(vector<int> &v,int num){
    int carry=0;
    fi(0,v.size()){
        int n=v[i]*num+carry;
        carry=n/10;
        v[i]=n%10;
    }
    while(carry){
        v.emplace_back(carry%10);
        carry/=10;
    }
}
void fun(){
    int n;
    cin>>n;
    vector<int> v;
    v.emplace_back(1);
    for(int i=2;i<=n;i++){
        mul(v,i);
    }
    for(int i=v.size()-1;i>=0;i--)
        cout<<v[i];
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