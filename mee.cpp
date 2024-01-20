
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 1e6+ 10, inf=2e18;
ll mod = 1000000007;
ll p, q, x, y;
ll dp[N];
ll func(ll ind, ll p, ll q, ll x, ll y){
    if(ind==0)return 0;
    if(dp[ind]!=0)return dp[ind];
    // cout<<ind<<endl;
    ll mi=min(p+func(ind-1, p-x, q, x, y), q+func(ind-1, p, q-y, x, y));
    if(ind>1)mi=min(p+q+func(ind-2, p-x, q-y, x, y), mi);
    return dp[ind]=mi;
}
void solve(ll tc)
{
    ll n;
    cin>>n;
    memset(dp, 0, sizeof(dp));
    cin>>p>>q>>x>>y;
    cout<<func(n, p,  q, x,  y);

}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

