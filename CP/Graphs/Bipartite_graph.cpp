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

//Bipartite Graph is a graph in which we can divide all nodes into two disjoint sets such that
//1. Each node belongs to exactly one of the disjoint set
//2. Each Edge connects nodes of two different sets

//If a graph contains a cycle of odd length, it is always a non-bipartite graph as it will
//always have two nodes which will belong to same dijoint set and are directly connected.Think
// of connection b/w last node and first node of a odd cycle.

vector<int> adj[mxsize];    //adjacency list
bool vis[mxsize], colour[mxsize];   //vis array for node transversal
bool dfs(int node, int col) {
    vis[node] = 1;
    colour[node] = col;
    for (auto child : adj[node]) {
        if (vis[child] == 0) {
            int c = col ^ 1;  //Flips the color,Turns 1 into 0 and 0 into 1.
            if (dfs(child, c) == 0)
                return 0;
        } else if (colour[child] == colour[node])
            return 0;
    }
    return 1;
}
void fun() {
    int n;  // number of nodes
    int k;  // number of edges
    cin >> n >> k;
    // 1 to n different type of nodes
    fi(0, k) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    fi(1, n + 1) {
        if (vis[i] == 0) {
            if (dfs(i, 1) == 0) {
                cout << "Graph is not Bipartite graph\n";
                return;
            }
        }
    }
    cout << "Graph is Bipartite\n";

    fi(0, n + 2) {
        colour[i] = vis[i] = 0;
        adj[i].clear();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/ATOM/input.txt", "r", stdin);
    freopen("/ATOM/output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--) {
        fun();
    }
}