#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
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
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define pl pair<ll,ll>
#define ppl pair<ll,pair<ll,ll>>
#define mxsize (int)5005

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n,m;
char a[mxsize][mxsize];
vector<vector<ll>> dis(mxsize,vector<ll>(mxsize,1e15));
vector<vector<bool>> vis(mxsize,vector<bool>(mxsize,0));

bool isvalid(int x,int y){
    return x>=0&&y>=0&&x<n&&y<m;
}

void bfs(int sx,int sy){
    queue<pair<int,int>> q;
    q.push({sx,sy});
    dis[sx][sy]=0;

    while(!q.empty()){
        int curx=q.front().F;
        int cury=q.front().S;
        q.pop();
        fi(0,4){
            int x=curx+dx[i];
            int y=curx+dy[i];
            if(!isvalid(x,y))   continue;





        }
    }

}

void fun(){
    cin>>n>>m;
    int sx,sy,dex,dey;
    fi(0,n){
        fj(0,m){
            cin>>a[i][j];


            if(a[i][j]=='S'){
                sx=i;   sy=j;
            }
            else if(a[i][j]=='D'){
                dex=i;  dey=j;
            }


        }
    }
    bfs(sx,sy);
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(20);
    cout<<fixed;
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