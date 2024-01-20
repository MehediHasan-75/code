#include<bits/stdc++.h>
using namespace std;
int main(){
    typedef long long ll;

    ll n, m, k;
    cin>>n>>m>>k;

    ll ans=n, need=max(0ll, n-k);
    vector<ll>dif;

    vector<ll>v(n);
    for(auto &it: v)cin>>it;

    for(ll i=1; i<n; i++){
        dif.push_back(v[i]-v[i-1]-1);
    }
    sort(dif.begin(), dif.end());


    for(ll i=0; i<need; i++){
        ans+=dif[i];
    }
    cout<<ans<<endl;
}