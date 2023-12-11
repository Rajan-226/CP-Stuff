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
#define mxsize (int)1e6
vector<int> adj[mxsize];    //adjacency list
int intime[mxsize],outtime[mxsize];
bool vis[mxsize];   //vis array for node transversal
int timer=0;
void dfs(int node){
    vis[node]=1;
    intime[node]=++timer;
    for(auto child:adj[node]){
        if(vis[child]==0){
            dfs(child);
        }
    }
    outtime[node]=++timer;
}
void fun(){
    int n;  // number of nodes
    int k;  // number of edges
    cin>>n>>k;
    // 1 to n different type of nodes
    fi(0,k){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    fi(1,n+1){
        if(vis[i]==0)
            dfs(i);
    }

    timer=0;
    fi(0,n+2){
        intime[i]=outtime[i]=vis[i]=0;
        adj[i].clear();
    }

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
}