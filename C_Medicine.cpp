
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
  ll n, k;
  cin>>n>>k;
  vector<pair<ll,ll>>v;
  v.push_back({0,0});
  ll sm=0;
  for(int i=0; i<n; i++){
    ll a, b;
    cin>>a>>b;
    v.push_back({a, b});
    sm+=b;
  }
  sort(all(v));
  if(sm<=k){
    cout<<1<<endl;
    return;
  }
  for(ll i=1; i<=n; i++){
    //cout<<sm-v[i-1].second<<" "<<v[i-1].second<<endl;
    if(sm-v[i-1].second<=k){
        cout<<v[i-1].first+1<<endl;;
        return;
    }
    else sm-=v[i-1].second;
  }
  cout<<v.back().first+1<<endl;
}
int main()
{
    fastio;ll T = 1;
    //cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

