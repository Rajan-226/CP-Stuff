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
vector<int> adj[mxsize+5];
vector<ll> dis(mxsize+5,INT_MAX);

void bfs(int n){
    queue<int> q;       // you can use priority queue if you want lexicographically smaller or larger
    
    for(int i=1;i<=n;i++){  //change here if node are 0 based
        if(indegree[i]==0)
            q.push(i);
        
    }

    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(auto node:adj[cur]){
            indegree[node]--;
            if(indegree[node]==0){
                q.push(node);
                if(dis[node]>dis[cur]+1){
                    dis[node]=dis[cur]+1;
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

        cin>>x>>y;

        adj[x].push_back(y);
        indegree[y]++;
    }

    int root=1;
    cin>>root;                  // We require Shortest distance from this node as root

    dis[root]=0;

    bfs(n);
    
    fi(1,n+1){
        if(dis[i]==INT_MAX)
            cout<<"Not Reachable from "<<root<<"\n";
        else
            cout<<dis[i]<<" ";
    }

    fi(0,n+2){
        indegree[i]=0;
        dis[i]=INT_MAX;
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
    cin>>t;
    while(t--){
        fun();
    }
}