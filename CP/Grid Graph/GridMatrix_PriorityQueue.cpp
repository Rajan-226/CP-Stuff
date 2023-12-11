#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007
#define pi 3.141592653589
#define nl cout<<"\n"
#define db(x) cout<<x<<" "
#define fi(a,b) for(int i=a;i<b;i++)
#define fj(a,b) for(int j=a;j<b;j++)
#define fk(a,b) for(int k=a;k<b;k++)
#define F first
#define S second

int fastexp(int a,int n,int nod=LLONG_MAX){
    int ans=1;
    while(n){
        if(n&1)
            ans=(ans*a)%nod;
        a=(a*a)%nod;
        n>>=1;
    }
    return ans;
}
#define mxsize (int)3e5
class Solution
{
public:
    struct my
    {
        int x, y, p;
        my(int X, int Y, int P)
        {
            x = X;
            y = Y;
            p = P;
        }
    };
    struct comp
    {
        bool operator()(my &a, my &b)
        {
            return a.p > b.p;
        }
    };
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        priority_queue<my, vector<my>, comp> q;
        bool vis[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                vis[i][j] = 0;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        q.push(my(0, 0, grid[0][0]));
        vis[0][0] = 1;
        while (!q.empty())
        {
            my par = q.top();
            q.pop();
            for (int j = 0; j < 4; j++)
            {
                int nx = par.x + dx[j];
                int ny = par.y + dy[j];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n)
                {
                    int req = max(par.p, grid[nx][ny]);
                    if (vis[nx][ny])
                        continue;
                    if (nx == n - 1 && ny == n - 1)
                        return req;
                    vis[nx][ny] = 1;
                    q.push(my(nx, ny, req));
                }
            }
        }
        return -1;
    }
};
void fun(){
    
}
/*

*/
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    cout<<fixed;
    //#ifndef ONLINE_JUDGE
    //	freopen("/ATOM/input.txt", "r", stdin);
    //	freopen("/ATOM/output.txt", "w", stdout);
    //#endif
    int t=1;
    cin>>t;
    while(t--){
        fun();
    }
}