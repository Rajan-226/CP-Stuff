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

//An articulation point (or cut vertex) is defined as a vertex which, when removed along with associated edges,
// makes the graph disconnected (or more precisely, increases the number of connected components in the graph).

//Root of a tree/graph is always a articulation point if it have more than 1 subtree
/*
    1
    5 5
    1 2
    2 3
    3 1
    3 4
    3 5             ans=1
*/
vector<int> adj[mxsize];    //adjacency list
bool vis[mxsize];   //vis array for node transversal
int low[mxsize],in[mxsize];
int timer=0;

set<int> points;

void dfs(int node,int par){
    vis[node]=1;
    low[node]=in[node]=++timer;
    int cnt=0;
    for(auto child:adj[node]){
        if(child==par)  continue;
        if(vis[child]==0){
            cnt++;
            dfs(child,node);
            low[node]=min(low[node],low[child]);
            if(low[child]>=in[node]&&par!=-1){
                points.insert(node);        //observe node is inserted here and not the child
            }
        }
        else{
            low[node]=min(in[child],low[node]);
        }
    }
    if(par==-1&&cnt>1)  //only for root node if it has greater than 1 subtree
        points.insert(node);
}
void fun(){
    int n;  // number of nodes
    int k;  // number of edges
    cin>>n>>k;
    fi(0,k){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    fi(1,n+1){
        if(vis[i]==0)
            dfs(i,-1);
    }
    
    cout<<points.size()<<"\n";


    fi(0,n+2){
        low[i]=in[i]=vis[i]=0;
        adj[i].clear();
    }
    timer=0;
    points.clear();

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