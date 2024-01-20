
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

    vector<ll>v(n);
    for(ll i=0; i<n; i++){
      cin>>v[i];
    }

    ll ans=0;
    for(ll i=30; i>=0; i--){
        ll cnt=0;
        for(ll j=0; j<n; j++){
            if(!(v[j]&(1ll<<i))){
                cnt++;
            }
        }
        if(cnt<=k){
            ans|=(1ll<<i);
            k-=cnt;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

