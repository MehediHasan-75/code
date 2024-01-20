#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n, k, x;
    cin>>n>>k>>x;

    vector<ll>v(n);
    for(auto &it:v)cin>>it;

    sort(v.begin(), v.end(), greater<ll>());

    for(ll i=1; i<n; i++)v[i]+=v[i-1];

    ll ans=v.back()-2*v[x-1];
    for(ll i=0; i<k; i++){
        ans=max(ans, v.back()-2*v[min(i+x, n-1)] + v[i]);
    }
    cout<<ans<<endl;
}
int main(){
    ll t;
    cin>>t;
    while(t--)solve();
}