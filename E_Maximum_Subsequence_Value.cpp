#include<bits/stdc++.h>
using namespace std;
int main(){
    typedef long long ll;
    ll n;
    cin>>n;

    vector<ll>v(n);
    for(auto &it: v)cin>>it;

    ll mx=0;

    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            ll ans=v[i]|v[j];
            for(ll k=0; k<n; k++){
                mx=max(mx, ans|v[k]);
            }
        }
    }
    cout<<mx<<endl;
}