#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 9, inf=2e18;
ll mod = 1000000007;
map<pair<ll,ll>,ll>mp;
vector<ll>taken(N,0);
ll n;
ll func(ll xo){
    ll first_free=-1;
    for(ll i=1; i<=n; i++){
        if(taken[i]==0){
            first_free=i;
            break;
        }
    }
    if(first_free==-1)return xo;
    taken[first_free]=1;
    ll mx=0;
    for(ll i=first_free+1; i<=n; i++){
        if(taken[i])continue;
        taken[i]=1;
        mx=max(mx,func(xo^mp[{first_free,i}]));
        taken[i]=0;
    }
    cout<<mx<<" ";
    return mx;
}
void solve(ll tc)
{
    cin>>n;
    for(ll i=1; i<=n; i++){
        for(ll j=i+1; j<=n; j++){
            ll a;
            cin>>a;
            mp[{i,j}]=a;
            mp[{j,i}]=a;
        }
    }
    cout<<func(0)<<endl;
}
int main()
{
    fastio;ll T = 1;
    //cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

