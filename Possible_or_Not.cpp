
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define prnt(x)            \
    for (auto &it : x)     \
        cout << it << " "; \
    cout << "\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 2e5 + 10, inf = 2e18;
ll mod = 1000000007;
void solve(ll tc)
{
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (auto &it : v)
        cin >> it;
    ll an=-1;
    vector<ll>vv;
    for (ll j = 0; j < n; j++)
    {
        if((v[j]&m)==m)vv.push_back(v[j]), an=v[j];
    }
    if(an!=-1){
        for(ll i=0; i<vv.size(); i++)an&=vv[i];
        if(an==m)cout<<"YES\n";
        else cout<<"NO\n";
    }
    else cout<<"NO\n";
}
int main()
{
    fastio;
    ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)
        solve(i);
    return 0;
}
