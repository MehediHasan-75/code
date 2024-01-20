#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
#define N 200005
ll fact[N], inv[N];
ll pwr(ll a,ll b)
{
    if(b==0) return 1;
    if(b%2==0) 
    {
        ll ret=pwr(a,b/2)%mod;
        return ((ret)*(ret))%mod;
    }
    else return ((a%mod)*(pwr(a,b-1)%mod))%mod;
    
}
void precal(){
    fact[0]=fact[1]=inv[1]=inv[0]=1;
    ll fac=1;
    for(ll i=2; i<N; i++){
        fac*=i;
        fac%=mod;
        fact[i]=fac;
        inv[i]=pwr(fac, mod-2);
    }
}
int main(){
    ll n, m, k;
    cin>>n>>m>>k;
    precal();
    ll ans=0;
    for(ll i=0; i<=k; i++){
        ans+=(((((((fact[n-1]*inv[i])%mod)*inv[n-1-i])%mod)*(m))%mod)*pwr(m-1, n-i-1))%mod;
        ans%=mod;
    }
    cout<<ans<<endl;
}