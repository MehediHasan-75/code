
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
ll func(ll a, ll b){
    ll val=abs(a-b);
    return val;
}
void solve(ll tc)
{
    ll n, k, a, b;
    cin>>n>>k>>a>>b;
    a--, b--;
    // cout<<a<<" "<<b<<endl;
    vector<pair<ll,ll>>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i].first>>v[i].second;
    }
    ll val=abs(v[a].first-v[b].first)+abs(v[a].second-v[b].second), vall=0;
    // cout<<val<<endl;
    ll dist1=val, dist2=val;
    for(ll i=0; i<k; i++){
        dist1=min(dist1, func(v[i].first, v[a].first) + func(v[i].second, v[a].second));
        dist2=min(dist2, func(v[i].first, v[b].first) + func(v[i].second, v[b].second));
    }
    cout<<min(val, dist1+dist2)<<endl;

}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

