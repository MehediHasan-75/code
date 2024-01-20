#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n, k;
    cin>>n>>k;

    map<ll,ll>mp;

    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        mp[(k-(a%k))%k]++;
    }
    pair<ll,ll>p={-1, 0};
    for(auto &it: mp){
        if(it.first==0)continue;
        if(it.second>=p.second)p=it;
    }
    if(p.first==-1){
        cout<<0<<endl;
        return;
    }
    ll ans=(p.second-1)*k + p.first +1;
    cout<<ans<<endl;
}
int main(){
    ll t;
    cin>>t;
    while(t--)solve();
}