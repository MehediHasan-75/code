
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
    ll n, m;
    cin>>n>>m;

    vector<ll>v(n);
    for(ll i=0; i<n; i++){
      cin>>v[i];
    }

    sort(all(v));
    ll ind=0, ans=0;

    vector<pair<ll, ll>>vv(m);
    for(ll i=0; i<m; i++){
        cin>>vv[i].second>>vv[i].first;
    }

    sort(all(vv), greater<pair<ll,ll>>());
    // prnt(v);
    // for(auto &it: vv)cout<<it.first<<" "<<it.second<<endl;
    for(ll i=0; i<vv.size(); i++){
        ll val=vv[i].first, times=vv[i].second;

        while(ind<n and v[ind]<val and times){
            ans+=val;
            ind++;
            times--;
        }
    }
    while(ind<n)ans+=v[ind], ind++;
    cout<<ans<<endl;
}
int main()
{
    fastio;ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

