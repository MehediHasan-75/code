#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
const int N=2e5+10;
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
int main(){
    fact_cal();
    ll n, m;
    cin>>n>>m;

    ll ans=nCrMod(m, n-1)%mod;

    ans=(ans*(n-2))%mod;
    ans=(ans*pwr(2, n-3))%mod;

    cout<<ans<<endl;
}