#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){
    ll n, n_;
    cin>>n;
    map<ll,ll>mpx, mpy, mpmi, mppl;
    vector<pair<ll,ll>>v(n);
    for(ll i=0; i<n; i++){
        ll x, y;
        cin>>x>>y;
        v[i]={x,y};
    }
    ll cnt=0;
    for(ll i=0; i<n; i++){
        ll x=v[i].first, y=v[i].second;
        cnt+=((mpx[x])+(mpy[y])+(mpmi[x-y])+(mppl[x+y]))*2;
        mpx[x]++;
        mpy[y]++;
        mppl[x+y]++;
        mpmi[x-y]++;
    }
    cout<<cnt<<endl;
}  
int main(){
    ll t;
    fastio;
    cin>>t;
    while(t--)solve();
}