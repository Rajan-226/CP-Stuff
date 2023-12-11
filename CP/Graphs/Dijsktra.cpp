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
#define mxsize (int)1e5+5

vector<pair<int,ll>> adj[mxsize];
vector<ll> dis(mxsize,(ll)1e18);
vector<bool> vis(mxsize,0);
vector<int> par(mxsize,0);

void dijsktra(int root){
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;       // you can use priority queue if you want lexicographically smaller or larger
    q.push({0,root});
    dis[root]=0;

    while(!q.empty()){
        int cur=q.top().S;
        q.pop();
        if(vis[cur])    continue;
        vis[cur]=1;

        for(auto child:adj[cur]){
            int node=child.first;
            int w=child.second;

            if(dis[node]>dis[cur]+w){
                par[node]=cur;
                dis[node]=dis[cur]+w;
                q.push({dis[node],node});
            }
        }
    }
}

void fun(){
    int n;  // number of nodes
    int k;  // number of edges
    cin>>n>>k;

    fi(0,k){
        int x,y;
        ll w;
        cin>>x>>y;

        cin>>w;                 

        adj[x].push_back({y,w});
        // adj[y].push_back({x,w});
    }

    dijsktra(1);        
        //check if graph is directed or undirected
    
    fi(1,n+1)
        cout<<dis[i]<<" ";
    nl;

    if(par[n]==0)
        cout<<"NO PATH\n";
    else{
        vector<int> path;       //Printing the path;

        for(int i=n;i!=1;i=par[i]){
            path.push_back(i);
        }
        path.push_back(1);

        reverse(path.begin(),path.end());
        for(auto i:path){
            db(i);
        }
        nl;
    }



    for(int i=0;i<=n;i++){
        adj[i].clear();
        dis[i]=(ll)1e18;
        vis[i]=0;
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
    cin>>t;
    while(t--){
        fun();
    }
}