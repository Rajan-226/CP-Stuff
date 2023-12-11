#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1000000007
#define pb push_back
#define nl cout<<"\n"
#define db(x) cout<<x<<" "
#define fi(a,b) for(int i=a;i<b;i++)
#define fj(a,b) for(int j=a;j<b;j++)
#define fk(a,b) for(int k=a;k<b;k++)
#define F first
#define S second
#define UM unordered_map<int,int>
#define MP map<int,int>
#define mxsize (int)1e6

int maxnode,diameter;
vector<int> adj[mxsize+5];
bool vis[mxsize+5];

void dfs(int node,int d){
    vis[node]=1;
    if(d>diameter){
        diameter=d;
        maxnode=node;
    }
    for(auto child:adj[node]){
        if(vis[child]==0){
            dfs(child,d+1);
        }
    }
}

void fun(){
    int n;
    cin>>n;
    maxnode=diameter=0;
    fi(0,n+1){
        vis[i]=0;
        adj[i].clear();
    }
    fi(0,n-1){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    
    dfs(1,0);         // In this dfs, we will find one end of the diameter

    fi(0,n+1)   vis[i]=0;
    diameter=0;
    int oneEnd=maxnode;
    dfs(maxnode,0);  // In this dfs, we will find other end of diameter
    int secondEnd=maxnode;
    cout<<diameter<<"\n";
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