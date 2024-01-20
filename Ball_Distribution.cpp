
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 3e5 + 10, inf=2e18;
ll mod = 1000000007;
void solve(ll tc)
{
   ll n, m, mi=INT64_MAX;
   cin>>n>>m;
   vector<ll>v(m);
   //unordered_map<ll,ll>mp;
   ll cnt=0, can=0;
   for(auto &it: v)cin>>it, mi=min(mi, it);
//    cout<<mi<<endl;
   for(ll i=0; i<m; i++){
    ll val=n-v[i];
    if(val<0){
        cout<<0<<endl;
        return;
    }
    cnt=max(cnt, val);
    can+=val;
   }
   //cout<<cnt<<" "<<can<<endl;
   mi-=can-cnt;
   cout<<max(0ll, mi)<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

