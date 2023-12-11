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
#define mxsize (int)2e4


//Bactracking + BFS
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
string ss="RLDU";
bool vis[mxsize][mxsize]={0};
char a[mxsize][mxsize];
int n,m;
int srcx,srcy,desx,desy;
char s[mxsize][mxsize];

bool isvalid(int x,int y){
    if(x<0||y<0||x>=n||y>=m)
        return 0;
    if(vis[x][y]||a[x][y]=='#'||a[x][y]=='A')   return 0;
    return 1;
}
bool bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    vis[x][y]=1;
    while(!q.empty()){
        int xx=q.front().F;
        int yy=q.front().S;
        q.pop();
        fi(0,4){
            if(isvalid(xx+dx[i],yy+dy[i])){
                int sx=xx+dx[i];
                int sy=yy+dy[i];
                q.push({sx,sy});
                vis[sx][sy]=1;
                s[sx][sy]=ss[i];
                if(sx==desx&&sy==desy){
                    return 1;
                }
            } 
        }
    }
    return 0;
}
void fun(){
    cin>>n>>m;
    fi(0,n){
        fj(0,m){
            cin>>a[i][j];
            if(a[i][j]=='A'){
                srcx=i;
                srcy=j;
            }
            if(a[i][j]=='B'){
                desx=i;
                desy=j;
            }
        }
    }
    if(bfs(srcx,srcy)){
        cout<<"YES\n";
        string ans="";
        ss="LRUD";
        while(desx!=srcx||desy!=srcy){
            ans+=s[desx][desy];
            int i=0;
            while(s[desx][desy]!=ss[i])
                i++;
            desx+=dx[i];
            desy+=dy[i];
        }   
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<"\n"<<ans<<"\n";
    }
    else{
        cout<<"NO PATH\n";
    }

    fi(0,n){
        fj(0,m){
            vis[i][j]=0;
        }
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