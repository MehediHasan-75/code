#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, m;
    cin>>n>>m;

    vector<pair<ll,ll>>v;

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            ll a;
            cin>>a;
            v.push_back({a, i});
        }
    }
    sort(v.begin(), v.end());

    set<ll>st;
    vector<ll>mp(n+1, 0);

    ll l=0, r=0, ans=INT64_MAX;

    while(r<v.size()){
        while(r<v.size() and st.size()<n){
            ll val=v[r].first, ind=v[r].second;

            mp[ind]++;
            st.insert(ind);
            r++;
        }
        while(r>l and st.size()==n){
            ans=min(ans, v[r-1].first-v[l].first);
            mp[v[l].second]--;

            if(mp[v[l].second]==0)st.erase(v[l].second);
            l++;
        }
    }
    cout<<ans<<"\n";
}