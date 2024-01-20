
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

typedef long long ll;
const ll N = 1e6 + 10, inf=2e18;
ll mod = 1000000007;

ll dp[N][2];

ll func(ll n, ll split){
    if(n==1)return 1;

    ll ans=0;
    if(dp[n][split]!=-1)return dp[n][split];
    if(split){
        ans=((func(n-1, 1)%mod)*4 + func(n-1, 0)%mod)%mod;
    }
    else{
        ans=((func(n-1, 0)%mod)*2 + func(n-1, 1)%mod);
    }
    return dp[n][split]=ans%mod;
}
void calc(){
    func(N-2, 0);
    func(N-2, 1);
}
void solve(ll tc)
{
    ll n;
    cin>>n;
    cout<<(func(n, 0)+func(n, 1))%mod<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    memset(dp, -1, sizeof(dp));
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

