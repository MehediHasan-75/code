
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 1000+10 , inf=2e18;
ll mod = 1000000007;
ll dr[N];
ll derange(ll n){
    if(n==1)return 0;
    if(n==0 or n==2)return 1;
    ll &ret=dr[n];
    if(ret!=0)return ret;
    return ret=(((n-1)%mod)*((derange(n-1)%mod+derange(n-2)%mod)%mod))%mod;
}
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
    cout<<"Case "<<tc<<": ";
    ll n, m, k;
    cin>>n>>m>>k;
    ll ans=0;
    for(ll i=0; i<=n-m; i++){
        ans=(ans%mod +((nCrMod(n-m,i)%mod)*derange(n-i-k)%mod)%mod)%mod;
    }
    cout<<(ans*nCrMod(m,k))%mod<<endl;
}
int main()
{
    fastio;ll T = 1;
    fact_cal();
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

