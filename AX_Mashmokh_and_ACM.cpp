
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 2001, inf=2e18;
ll mod = 1000000007;
ll n, k;
ll dp[N][N];
ll func(ll len, ll prev){
    if(len==k)return 1;
    if(dp[len][prev])return dp[len][prev];
    ll cnt=0;
    for(ll i=prev; i<=n; i+=prev){
        cnt+=func(len+1, i)%mod;
        cnt%=mod;
    }
    return dp[len][prev]=cnt;
}
void solve(ll tc)
{
    cin>>n>>k;
    cout<<func(0, 1);
}
int main()
{
    fastio;ll T = 1;
    //cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

