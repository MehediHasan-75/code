
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 2e5 + 10, inf=2e18;
ll mod = 1000000007;
void solve(ll tc)
{
    ll n, m;
    cin>>n>>m;
    ll mx=-1;
    for(ll i=9; i>=1; i--){
        ll num=0;
        for(ll dig=1; dig<=n; dig++){
            num=num*10+i;
            num%=m;
            if(num==0){
                mx=max(mx,dig);
            }
        }
    }
    if(mx==-1)cout<<-1<<endl;
    else{
    for(ll i=9; i>=1; i--){
        ll num=0, mxx=-1;
        for(ll dig=1; dig<=n; dig++){
            num=num*10+i;
            num%=m;
            if(num==0){
                mxx=max(mxx,dig);
            }
        }
        if(mxx==mx){
            for(ll j=0; j<mx; j++)cout<<i;
            break;
        }
    }       
    }
}
int main()
{
    fastio;ll T = 1;
    //cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

