
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 2e5 + 10, inf=2e18;
ll mod = 1000000007;
void solve(ll tc)
{
    ll n;
    cin>>n;
    vector<ll>v(n), d(n);
    map<ll,ll>mp;
    for(auto &it: v)cin>>it, mp[it]++;
    for(auto &it: d)cin>>it, mp[it]++;
    // vector<pair<ll,ll>>vv;
    // for(ll i=0; i<n; i++){
    //     vv.push_back({v[i], 0});
    //     vv.push_back({d[i], 1});
    // }
    // ll mx=0, cnt=0;
    // sort(all(vv));
    // for(ll i=0; i<n; i++){
    //     if(vv[i].second==0)cnt++;
    //     else cnt--;
    //     mx=max(mx, cnt);
    // }
    ll mx=0;
    for(auto &it: mp)mx=max(it.second, mx);
    cout<<mx<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

