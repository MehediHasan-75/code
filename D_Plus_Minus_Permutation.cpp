
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
ll val(ll n){
    return n*(n+1)/2;
}
void solve(ll tc)
{
    ll n, x, y;
    cin>>n>>x>>y;
    ll xx=n/x, yy=n/y, xy=n/((x*y)/__gcd(x, y));
    yy-=xy;
    xx-=xy;
    cout<<val(n) - val(n-xx) - val(yy)<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

