
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
ll fact[N];

ll pwr(ll a,ll b)
{
    if(b==0) return 1;
    ll ret=pwr(a,b/2)%mod;
    if(b%2==0) 
    {
        return ((ret)*(ret))%mod;
    }
    else return ((a%mod)*(((ret)*(ret))%mod))%mod;
    
}
ll inverseMod(ll a){
   return pwr(a, mod-2);
}
ll nCrMod(ll n, ll r){
    if(r==0)return 1;
    if(r>n) return 0;
    return (fact[n]*inverseMod(fact[r]*fact[n-r]%mod))%mod;
}

void fact_cal(){
    fact[0]=1;
    for(ll i=1; i<N; i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
}
void solve(ll tc)
{
    ll n, m, k;
    cin>>n>>m>>k;

    if(k+1!=m){
        cout<<0<<endl;
        return;
    }
    ll stars=m-1, bars=n-m-1;
    cout<<nCrMod(stars+bars, stars)<<endl;
}
int main()
{
    fastio;ll T = 1;
    // cin >> T;
    fact_cal();
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

