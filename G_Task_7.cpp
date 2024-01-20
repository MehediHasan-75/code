
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

  vector<pair<ll,ll>>v(n);
  for(auto &it: v)cin>>it.first>>it.second;
  
  auto cmp=[&](pair<ll,ll>p1, pair<ll,ll>p2){
    if(p1.first!=p2.first)return p1.first<p2.first;
    return p1.second>p2.second;
  };
  sort(all(v), cmp);
  for(auto &[x, y]: v)cout<<x<<" "<<y<<"\n";  
}
int main()
{
    ios_base::sync_with_stdio(false);
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

