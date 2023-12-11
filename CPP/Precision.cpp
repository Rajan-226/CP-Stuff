#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define nl cout<<"\n"
#define db(x) cout<<x<<" "
#define fi(a,b) for(int i=a;i<b;i++)
#define fj(a,b) for(int j=a;j<b;j++)
#define fk(a,b) for(int k=a;k<b;k++)
#define F first
#define S second
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
#define mxsize (int)1e6
// When outputting floating point numbers, cout has a default 
// precision of 6 and it truncates anything after that.

void fun(){
    double x = 1.411;
    double y = 1.56;
    
    cout<<trunc(x)<<"\n";   //Trunc rounds removes digits after decimal point.

    cout<<round(x)<<" "<<round(y)<<"\n";    //Rounds given number to the closest integer.

    cout << fixed << setprecision(10) <<x<< "\n";     // gives the value upto 10 decimal points
    cout << fixed << setprecision(30) <<1.0/3.0<< "\n";     // gives the value upto 10 decimal points
    

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