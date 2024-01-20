#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n, m;
    cin>>n>>m;
    vector<ll>v(n);
    for(auto &it: v)cin>>it;
    if(n>m)cout<<0<<endl;
    else{
        ll ans=1;
        for(ll i=0; i<n; i++){
            for(ll j=i+1; j<n; j++){
                ans=(ans*(abs(v[i]-v[j])%m))%m;
            }
        }
        cout<<ans<<endl;
    }
}