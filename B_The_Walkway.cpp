#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
  ll n, m, d;
  cin>>n>>m>>d;
  vector<ll>v(m);
  for(auto &it: v)cin>>it, it--;
  v.insert(v.begin(), 0), v.emplace_back(n);
  ll total=0;
  auto can= [&d](ll l, ll r){
    return (r-l+d-1)/d;
  };
  for(ll i=0; i<v.size()-1; i++)total+=can(v[i], v[i+1]);
  // cout<<total<<endl;
  ll cnt=0, ans= INT64_MAX;
  for(ll i=1; i<=m; i++){
    ll cur= total - can(v[i-1], v[i]) - can(v[i], v[i+1]) + can(v[i-1], v[i+1]);
    if(cur<ans)ans=cur, cnt=1;
    else if(ans==cur)cnt++;
  }
  cout<<ans<<" "<<cnt<<endl;
}
int main(){
  ll t;
  cin>>t;
  while(t--)solve();
}