
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
ll dp[N], use[N];
ll func(ll n, ll k){
    if(k==0)return 1;
    if(k<0)return 0;
    if(dp[k])return dp[k];
    ll fl=0;
    for(ll i=1; i<=k; i++){
        if(use[i]<2){
            use[i]++;
            fl|=func(n, k-i);
        }
    }
    return fl;
}
void solve(ll tc)
{
    cout<<"Case "<<tc<<": ";
    ll n, k;
    cin>>n>>k;
    func();
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

