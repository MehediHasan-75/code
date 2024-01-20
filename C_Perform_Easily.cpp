#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    typedef long long ll;
    vector<ll>vv(6);
    for(auto &it: vv)cin>>it;

    ll n;
    cin>>n;

    vector<pair<ll,ll>>v;

    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        for(ll j=0; j<6; j++){
            v.push_back({a-vv[j], i});
        }
    }
    sort(v.begin(), v.end());
    ll mi=INT64_MAX;

    set<ll>st;
    vector<ll>mp(200000+10, 0);

    ll l=0;
    for(ll r=0; r<v.size();){
        while(r<v.size() and st.size()<n){
            mp[v[r].second]++;
            st.insert(v[r].second);
            r++;
        }
        while(l<r and st.size()>=n){
            mi=min(mi, v[r-1].first-v[l].first);
            mp[v[l].second]--;

            if(mp[v[l].second]==0){
                st.erase(st.find(v[l].second));
            }
            l++;
        }
    }
    cout<<mi<<endl;
}