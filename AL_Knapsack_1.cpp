
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 2e5 + 10, inf=2e18;
ll mod = 1000000007, n, w;
vector<ll>wt(N), val(N);
ll dp[N][101];
ll func(ll rem, ll ind){
    if(rem<=0 or ind==n)return 0;
    if(dp[rem][ind]!=-1)return dp[rem][ind];
    ll mx=0;
    if(rem-wt[ind]>=0)mx=max(mx, val[ind]+func(rem-wt[ind], ind+1));
    mx=max(mx, func(rem, ind+1));
    return dp[rem][ind]=mx;
}
void solve(ll tc)
{
    memset(dp, -1, sizeof(dp));
    cin>>n>>w;
    for(ll i=0; i<n; i++)cin>>wt[i]>>val[i];
    cout<<func(w, 0);
}
int main()
{
    fastio;ll T = 1;
   // cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

