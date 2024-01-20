
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
    ll n, m;
    cin>>n>>m;
    vector<ll>v(n*m);
    for(auto &it: v)cin>>it;
    sort(all(v), greater<ll>());
    ll x=(n*m-min(n,m))*(v[0]-v.back())+(min(n,m)-1)*(v[1]-v.back());
    ll y=(n*m-min(n,m))*(v[0]-v[n*m-1])+(min(n,m)-1)*(v[0]-v[n*m-2]);
    cout<<max(x,y)<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

