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

//If there is a backedge,then there is a cycle.

vector<int> adj[mxsize];    //adjacency list
bool vis[mxsize];   //vis array for node transversal
int parent[mxsize];
int cyc_strt=-1,cyc_end=-1;

bool dfs(int node,int par){
    vis[node]=1;
    for(auto child:adj[node]){
        if(vis[child]==0){
            parent[child]=node;
            if(dfs(child,node)==1)
                return 1;
        }
        else if(child!=par){
            cyc_end=node;
            cyc_strt=child;
            return 1;
        }
    }
    return 0;
}
void fun(){
    int n;  // number of nodes
    int k;  // number of edges
    cin>>n>>k;
    fi(0,n+2){
        parent[i]=vis[i]=0;
        adj[i].clear();
    }
    fi(0,k){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    fi(1,n+1){
        if(vis[i]==0){
            if(dfs(i,i)==true){
                cout<<"There is a cycle\n";

                vector<int> ans;                   //For printing the cycle 
                ans.push_back(cyc_strt);
                for(int i=cyc_end;i!=cyc_strt;i=parent[i]){
                    ans.push_back(i);
                }
                ans.push_back(cyc_strt);
                reverse(ans.begin(),ans.end());

                cout<<ans.size()<<"\n";         //Cycle Size
                fi(0,ans.size())
                    db(ans[i]);                 //Printing the cycle
                return ;
            }
        }
    }
    cout<<"There is no cycle\n";
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