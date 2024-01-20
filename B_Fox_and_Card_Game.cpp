#include<bits/stdc++.h>
using namespace std;
int main(){
    typedef long long ll;
    ll n;
    cin>>n;

    map<ll, ll>mp;
    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        mp[a]++;
    }
    ll ans=0, cnt=0;
    for(ll i=1; i<=n; i++){
        ll nm=mp[i];
        ans+=(nm*(nm-1))/2 *cnt;
        ans+=(nm*(nm-1)*(nm-2))/6;
        cnt+=nm;
    }
    cout<<ans<<endl;
}