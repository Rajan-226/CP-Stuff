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
ll fastexp(ll a,ll n,ll nod=LLONG_MAX){
    ll ans=1;
    while(n){
        if(n&1)
            ans=(ans*a)%nod;
        a=(a*a)%nod;
        n>>=1;
    }
    return ans;
}

#define vvl vector<vector<ll>>
#define vl vector<ll>
#define pl pair<ll,ll>
#define ppl pair<ll,pair<ll,ll>>
#define mxsize (int)1e6+5

void fun(){
    int n;
	cin>>n;
	ll a[n];
	fi(0,n)	cin>>a[i];

    
	vector<int> div(mxsize,0);
	fi(0,n){
		int num=a[i];
		for(int i=2;i*i<=num;i++){
			if(num%i==0){
				int c=0;
				while(num%i==0){
					num/=i;
					c++;
				}
				div[i]=max(div[i],c);
			}
		}
		if(num>1){
			div[num]=max(div[num],1);
		}
	}
	ll lcm=1;
	fi(2,mxsize){
		while(div[i]--){
			lcm=(lcm*i)%mod;
		}
	}
    cout<<lcm<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(20);
    cout<<fixed;
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