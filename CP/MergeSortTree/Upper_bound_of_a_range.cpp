#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
#define mxsize (int)1005
int input[mxsize];
vector<int> tree[mxsize];
void build(int si,int ss,int se){
    if(ss==se){
        tree[si].push_back(input[ss]);
        return ;
    }
    int mid=(ss+se)/2;
    build(2*si,ss,mid);
    build(2*si+1,mid+1,se);
    int i=0,j=0;
    while(i<(int)tree[2*si].size()&&j<(int)tree[2*si+1].size()){
        if(tree[2*si][i]<tree[2*si+1][j]){
            tree[si].push_back(tree[2*si][i++]);
        }else{
            tree[si].push_back(tree[2*si+1][j++]);
        }
    }
    while(i<(int)tree[2*si].size()){
        tree[si].push_back(tree[2*si][i++]);
    }
    while(j<(int)tree[2*si+1].size()){
        tree[si].push_back(tree[2*si+1][j++]);
    }
}
int query(int si,int ss,int se,int qs,int qe,int k){
    if(ss>qe||se<qs)    return 0;
    if(ss>=qs&&se<=qe){
        int ind=upper_bound(tree[si].begin(),tree[si].end(),k-1)-tree[si].begin();
        return ind;
    }
    int mid=(ss+se)/2;
    return query(2*si,ss,mid,qs,qe,k)+query(2*si+1,mid+1,se,qs,qe,k);
}
void print(int si,int ss,int se){
    cout<<ss<<" "<<se<<"\n";
    for(auto i:tree[si]){
        cout<<i<<" ";
    }
    cout<<"\n\n";

    if(ss==se)  return;
    int mid=(ss+se)/2;
    print(2*si,ss,mid);
    print(2*si+1,mid+1,se);
}
void fun(){
    // To find number of elements strictly smaller than k in range l to r
    int n;
    cin>>n;
    fi(1,n+1)   cin>>input[i];
    build(1,1,n);
    // print(1,1,n);
    int q;
    cin>>q;
    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        cout<<query(1,1,n,l,r,k)<<"\n";
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(20);
    cout<<fixed;
    // #ifndef ONLINE_JUDGE
    //     freopen("/ATOM/input.txt", "r", stdin);
    //     freopen("/ATOM/output.txt", "w", stdout);
    // #endif
    int t=1;
    // cin>>t;
    while(t--){
        fun();
    }
}