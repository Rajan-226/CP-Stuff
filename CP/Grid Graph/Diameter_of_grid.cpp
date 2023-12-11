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
#define mxsize (int)1e3

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int r,c;
char a[mxsize][mxsize];
bool vis[mxsize][mxsize];
int ans=0;
int nodex,nodey;

bool isvalid(int x,int y){
    return x>=0&&y>=0&&x<=r&&y<=c&&vis[x][y]==0&&a[x][y]=='.';
}

void dfs(int x,int y,int d){
    vis[x][y]=1;
    if(ans<=d){
        ans=d;
        nodex=x;
        nodey=y;
    }
    fi(0,4){
        if(isvalid(x+dx[i],y+dy[i])){
            dfs(x+dx[i],y+dy[i],d+1);
        }
    }
}

void fun(){             // this is valid if there is only 1 connected component in grid
    cin>>r>>c;
    int srcx=0,srcy=0;
    fi(0,r){
        fj(0,c){
            cin>>a[i][j];
            if(a[i][j]=='.'){
                srcx=i;
                srcy=j;
            }
            vis[i][j]=0;
        }
    }
    ans=0;
    dfs(srcx,srcy,1);           //just use 0 here if you want diameter-1
    fi(0,r){
        fj(0,c){
            vis[i][j]=0;
        }
    }
    ans=0;
    dfs(nodex,nodey,1);          //just use 0 here if you want diameter-1

    cout<<ans<<"\n";
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