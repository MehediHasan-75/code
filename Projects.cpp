#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define ll long long
vector<ll>dp(N, -1);

ll func(vector<pair<pair<ll,ll>, ll>> &v, ll ind){
    if(ind==v.size())return 0;

    ll l=v[ind].first.first, r=v[ind].first.second, w=v[ind].second;
    ll lo=0, hi=v.size()-1, valid_ind=v.size();
    if(dp[ind]!=-1)return dp[ind];
    while(lo<=hi){
        ll mid=(hi+lo)>>1;

        if(v[mid].first.first<=r)lo=mid+1;
        else{
            hi=mid-1;
            valid_ind=mid;
        }
    }
    ll ans=max(func(v, ind+1), w+func(v, valid_ind));
    return dp[ind]=ans;
}
int main(){
    ll n;
    cin>>n;
    vector<pair< pair<ll,ll>, ll> >v(n);
    set<pair<ll,ll>>st;
    for(ll i=0; i<n; i++){
        ll l, r, w;
        cin>>l>>r>>w;
        v[i]={{l, r}, w};
    }
    sort(v.begin(), v.end());
    // memset(dp, -1, sizeof(dp));
    // for(auto &it: v)cout<<it.first.first<<" "<<it.first.second<<" "<<it.second<<endl;
    cout<<func(v, 0)<<endl;

}