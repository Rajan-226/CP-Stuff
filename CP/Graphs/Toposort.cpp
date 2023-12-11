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
//Topological sort is an order in which node which will be transversed first in dfs comes first in toposort order

//Toposort can be non-unique for a same graph
//It exists only for a directed acyclic graph(DAG)

//We are using Kahn's algorithm here
int indegree[mxsize+5];
vector<int> adj[mxsize+5];
vector<int> tsort;

void kahn(int n){
    queue<int> q;       // Just change this to priority queue if you want lexicographically smaller or larger.
                        //For lexicographically larger, just use priority_queue<int> q;
            
    for(int i=1;i<=n;i++){  //change here if node are 0 based
        if(indegree[i]==0)
            q.push(i);
    }
    while(!q.empty()){
        int cur=q.front();
        tsort.push_back(cur);
        q.pop();
        for(int node:adj[cur]){
            indegree[node]--;
            if(indegree[node]==0)
                q.push(node);
        }
    }
    if((int)tsort.size()==n){
        cout<<"Toposort :\n";
        for(auto i:tsort){
            db(i);
        }
    }
    else{
        cout<<"No Toposort\n";
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

    kahn(n);


    fi(0,n+2){
        indegree[i]=0;
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