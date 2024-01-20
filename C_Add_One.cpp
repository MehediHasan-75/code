
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
ll dp[10][N];
ll func(ll dig, ll op){
    if(op==0)return 1;
    if(dp[dig][op]!=-1)return dp[dig][op];
    if(dig<9)return dp[dig][op]=func(dig+1, op-1)%mod;
    else return dp[dig][op]=(func(0, op-1)%mod + func(1, op-1)%mod)%mod;
}
void solve(ll tc)
{
    ll n, m;
    cin>>n>>m;
    ll cnt=0;
    while(n){
        ll dig=n%10;
        n/=10;
        cnt+=func(dig, m);
        cnt%=mod;
    }
    cout<<cnt<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    memset(dp, -1, sizeof(dp));
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

