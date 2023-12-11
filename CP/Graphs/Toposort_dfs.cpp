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
int vis[mxsize];   //vis array for node transversal
vector<int> tsort;
bool ok;
void dfs(int node,int par){
    vis[node]=1;
    for(auto child:adj[node]){
        if(vis[child]==0){
            dfs(child,node);
        }
        else if(vis[child]==1)
            ok=1;
    }
    vis[node]=2;
    tsort.push_back(node);
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
    }
    ok=0;

    fi(1,n+1){
        if(vis[i]==0)
            dfs(i,-1);
    }

    reverse(tsort.begin(),tsort.end());

    if(ok){
        cout<<"No toposort\n";
    }
    else{
        // toposort order is in tsort vector

    }

    fi(0,n+2){
        vis[i]=0;
        adj[i].clear();
    }
    tsort.clear();

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