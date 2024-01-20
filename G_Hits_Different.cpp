#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2023;
vector<ll>v[N];
map<ll, pair<ll,ll>>mp;
void precalc(){
    ll num=1; 
    for(ll i=1; i<N; i++){
        v[i].push_back(0);
        for(ll j=1; j<=i; j++){
            v[i].push_back(num*num+ v[i].back());
            mp[num]={i, j};
            num++;
        }
    }
}
void solve(){
    ll n;
    cin>>n;
    ll r=mp[n].second, l=r, ind=mp[n].first;
    ll ans=0;
    while(ind>0){
        ans+= v[ind][r]-v[ind][l-1];
        // cout<<v[ind][r]<<" "<< v[ind][l-1]<</" "<<endl;
        ind--;
        r=min(r, (ll)v[ind].size()-1);
        l=max(1ll, l-1);
    }
    cout<<ans<<endl;
}
int main(){
    ll t;
    cin>>t;
    precalc();
    while(t--)solve();
}