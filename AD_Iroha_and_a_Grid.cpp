#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define N 200005
using namespace std;
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
ll ways(ll ux, ll uy, ll dx, ll dy){
    return (((fact[dx-ux+dy-uy]*inverseMod(fact[dx-ux]))%mod)*inverseMod(fact[dy-uy]))%mod;
}
int main(){
    ll r, c, a, b;
    cin>>r>>c>>a>>b;
    fact_cal();
    ll ans=ways(1, 1, r, c);
    for(ll i=0; i<a; i++){
        ll row=r-i, col=b;
        ans-=(ways(1, 1, row, col)*ways(row, col+1, r, c))%mod;
        ans=(ans+mod)%mod;
    }
    cout<<((ans+mod)%mod)<<endl;
}