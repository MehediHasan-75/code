#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    map<ll,ll>mp;
    ll mx=0;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        mx=max(mx,x);
        mp[x-i]+=x;
    }
    for(auto &it: mp)mx=max(mx,it.second);
    cout<<mx<<endl;
}