#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
void solve(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    map<ll,ll>mp;
    for(auto &it: v)cin>>it, mp[it]++;
    vector<vector<ll>> bits(32);
    for(ll i=0; i<n; i++){
        for(ll bt=0; bt<32; bt++){
            if(v[i]&(1ll<<bt))bits[bt].push_back(v[i]);
        }
    }
    vector<ll>ans;
    ll orr=0;
    for(ll i=31; i>=0; i--){
        if(orr&(1ll<<i))continue;

        if(bits[i].size()){
            ll temp=orr, num=-1;
            for(auto &it: bits[i]){
               
                if((orr|it) > temp){
                    num=it;
                    temp=orr|it;
                }
            }
            orr=temp;
            ans.push_back(num);
            mp[num]--;
        }
    }
    
    for(auto &it: mp){
        while(it.second--)ans.push_back(it.first);
    }
    for(auto &it: ans)cout<<it<<" ";
    cout<<endl;
}
int main(){
    fastio;
    ll t;
    cin>>t;
    while(t--)solve();
}