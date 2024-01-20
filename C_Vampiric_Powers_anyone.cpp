
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
    ll mx=0, cur_xo=0;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
      cin>>v[i];
    }
    vector<ll>mp(1000, 0);
    for(ll i=0; i<n; i++){
        cur_xo^=v[i];
        for(ll xo=0; xo<=(1<<8); xo++){
            if(mp[xo]){
                mx=max(mx, max(cur_xo, cur_xo^xo));
            }
        }
        // mx=max(cur_xo, mx);
        mp[cur_xo]++;
    }
    cout<<mx<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

