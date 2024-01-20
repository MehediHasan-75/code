#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007
map<ll,ll>mp;
void divi(ll n){
    ll n_=n;
    for(ll i=2; i<=sqrt(n); i++){
        while(n_%i==0){
            mp[i]++;
            n_/=i;
        }
    }
    if(n_>1)mp[n_]++;
}
int main(){
    ll n;
    cin>>n;
    for(ll i=2; i<=n; i++){
        divi(i);
    }
    if(n==1)cout<<1<<endl;
    else{
        ll total=1;
        for(auto &it: mp){
            total%=mod;
            total*=(it.second+1)%mod;
            total%=mod;
        }
        cout<<total<<endl;
    }
}