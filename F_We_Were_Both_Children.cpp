#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n;
    cin>>n;
    vector<ll>v(n+1, 0), cnt(n+1,0);
    map<ll,ll>mp;
    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        if(a<=n)mp[a]++, v[a]++;
    }
    ll mx=0;
    for(auto &it: mp){
        mx=max(mx, it.second);
        for(ll i=it.first*2; i<=n; i+=it.first){
            v[i]+=it.second;
            mx=max(mx, v[i]);
        }
    }
    cout<<mx<<endl;
}
int main(){
    ll t;
    cin>>t;
    while(t--)solve();
}