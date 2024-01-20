#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int Log=21, mxN=1<<Log;
#define mod 1000000007
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
vector<ll> sos(mxN, 0);
ll pwr(ll a,ll b)
{
    if(b==0) return 1;
    if(b%2==0) 
    {
        ll ret=pwr(a,b/2)%mod;
        return ((ret%mod)*(ret%mod))%mod;
    }
    else return ((a%mod)*(pwr(a,b-1)%mod))%mod;
    
}
int main(){
    fastio;
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(auto &it: v)cin>>it, sos[it]++;
    for(ll i=0; i<Log; i++){
        for(ll j=0; j<mxN; j++){
            if((j&(1<<i))==0){
               sos[j]=(sos[j]+sos[j^(1<<i)])%mod;
            }
        }
    }
    for(ll j=0; j<mxN; j++){
        sos[j]=(pwr(2, sos[j]%mod)-1+mod)%mod;
    }
    for(ll i=0; i<Log; i++){
        for(ll j=mxN-1; j>=0; j--){
            if((j&(1ll<<i))==0){
               sos[j]-=sos[j^(1<<i)];
               if(sos[j]<0)sos[j]+=mod;
            }  
        }
    }
    cout<<sos[0];
}