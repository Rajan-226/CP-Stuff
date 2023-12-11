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

int indegree[mxsize+5];
vector<pair<int,ll>> adj[mxsize+5];
vector<ll> dis(mxsize+5,INT_MIN);


void bfs(int n){
    queue<int> q;       // you can use priority queue if you want lexicographically smaller or larger
    
    for(int i=1;i<=n;i++){  //change here if node are 0 based
        if(indegree[i]==0){
            q.push(i);
            dis[i]=0;
        }
    }

    while(!q.empty()){
        int cur=q.front();
        
        q.pop();
        for(auto p:adj[cur]){
            int node=p.first;
            int w=p.second;
            indegree[node]--;
            if(indegree[node]==0){
                q.push(node);
                if(dis[p.F] < dis[cur]+w){
                    dis[p.F]=dis[cur]+w;
                }
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
        ll w=1;
        cin>>x>>y;
        
        // cin>>w;

        adj[x].push_back({y,w});
        indegree[y]++;
    }
    
    bfs(n);
    
    ll ans=0;
    fi(1,n+1){
        ans=max(ans,dis[i]);
    }

    cout<<ans<<"\n";

    fi(0,n+2){
        indegree[i]=0;
        dis[i]=INT_MIN;
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