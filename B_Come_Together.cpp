
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
    ll a, b;
    cin>>a>>b;
    ll x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;
    ll ans=1;
    ans+=max(0ll, min(y1-b, y2-b));
    //cout<<ans<<endl;
    ans+=max(0ll, min(b-y1, b-y2));
    //cout<<ans<<endl;
    ans+=max(0ll, min(x1-a, x2-a));
    //cout<<ans<<endl;
    ans+=max(0ll, min(a-x1, a-x2));
    cout<<ans<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

