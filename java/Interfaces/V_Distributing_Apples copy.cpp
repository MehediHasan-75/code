#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007
const int N=1e6+10;
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
    for(ll i=1; i<N; i++){

        fact[i]=fac;
        inv[i]=pwr(fac, mod-2)%mod;
    }
}
int main(){
    ll n, m;
    cin>>n>>m;
    ll fac=1, inv_m=1, inv_n_1=1;
    for(ll i=1; i<=m+n-1; i++){
        fac*=i;
        fac%=mod;
        if(i==m)inv_m=fac;
        if(i==n-1)inv_n_1=fac;
    }
    precal();
    ll ans=0;
    ans=((fac*pwr(inv_n_1, mod-2))%mod)*(pwr(inv_m, mod-2)%mod);
    cout<<ans%mod<<endl;
}