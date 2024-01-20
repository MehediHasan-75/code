#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007
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
    ll n, k;
    cin>>n>>k;
    ll b=k, r=n-k;
    //cout<<pwr(2, 65);
    precal();
    ll ans=0;
    for(ll i=1; i<=k; i++){
        if((r+1)<i or (b-1)<(i-1))cout<<0<<endl;
        else{
          ans=(((((((((fact[r+1]*inv[i])%mod)*inv[r+1-i])%mod)*fact[b-1])%mod)*inv[b-1-i+1])%mod)*inv[i-1])%mod;
          cout<<ans<<endl;
        }
    }
}