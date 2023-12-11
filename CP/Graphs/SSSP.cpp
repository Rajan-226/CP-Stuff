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
#define UM unordered_map<int,int>
#define MP map<int,int>
#define mxsize (int)1e6
int n,k;
vector<int> adj[mxsize+5];
int bfs(int parent,int des){
    queue<int> q;
    q.push(parent);
    vector<bool> vis(n+4,0);
    vector<int> dis(n+4,0);
    vis[parent]=1;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int node:adj[cur]){
            if(vis[node]==0){
                q.push(node);
                vis[node]=1;
                dis[node]=dis[cur]+1;
                if(node==des)
                    return dis[node];
            }
        }
    }
}
void fun(){
    cin>>n>>k;
    fi(0,k){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int src,des;
    cin>>src>>des;
    cout<<bfs(src,des)<<"\n";
    fi(0,n+2){
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