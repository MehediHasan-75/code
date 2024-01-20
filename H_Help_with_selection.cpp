
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 1e6 + 10, inf=2e18;
ll fact[N];
ll pwr(ll a,ll b, ll mod)
{
    if(b==0) return 1;
    ll ret=pwr(a,b/2, mod)%mod;
    if(b%2==0) 
    {
        return ((ret)*(ret))%mod;
    }
    else return ((a%mod)*(((ret)*(ret))%mod))%mod;
    
}
ll inverseMod(ll a, ll mod){
   return pwr(a, mod-2, mod);
}
ll nCr(ll n, ll r, ll mod){
    if(r>n)return 0;
    ll div=1, mul=1;
    for(ll i=0; i<r; i++){
        mul*=(n-i);
        mul%=mod;
        div*=(i+1);
        div%=mod;
    }
    return (mul*inverseMod(div, mod))%mod;
}
void solve(ll tc){
    ll x, y, p;
    cin>>x>>y>>p;
    vector<ll>n,r;
    while(x!=0 or y!=0){
        n.push_back(x%p);
        r.push_back(y%p);
        x/=p;
        y/=p;
    }
    ll ans=1;
    //for(ll i=0; i<n.size(); i++)cout<<n[i]<<" "<<r[i]<<endl;
    for(ll in=0; in<n.size(); in++){
        ans*=nCr(n[in], r[in], p);
        ans%=p;
    }
    cout<<ans<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

