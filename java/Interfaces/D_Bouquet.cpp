#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll pwr(ll a,ll b)
{
    if(b==0) return 1;
    if(b%2==0) 
    {
        ll ret=pwr(a,b/2)%mod;
        return ((ret)*(ret))%mod;
    }
    else return ((a%mod)*(pwr(a,b-1))%mod)%mod;
    
}
ll binomialCoeff(ll n, ll k)
{
    ll res = 1;
 
    if ( k > n - k )
        k = n - k;
 
    for (ll i = 0; i < k; ++i)
    {
        res *= (n - i);
        res%=mod;
    }
    ll fack=1;
    for(ll i=2; i<=k; i++){
        fack*=i;
        fack%=mod;
    }
    res*=pwr(fack, mod-2)%mod;
    return res%mod;
}
int main(){
    ll n, a, b;
    cin>>n>>a>>b;
    ll on=binomialCoeff(n,a), tw=binomialCoeff(n, b);
    on%=mod, tw%=mod;
    // cout<<on<<" "<<tw<<endl;
    // cout<<pwr(2,n)<<endl;
    ll total=((pwr(2, n))%mod-1-(on+tw)%mod)%mod;
    total=(total+mod)%mod;
    cout<<total<<endl;

}