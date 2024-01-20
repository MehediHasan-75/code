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
ll mod = 998244353;
vector<ll> fact(N);
void solve()
{
    string s;
    cin >> s;
    ll ans = 1, tot = 0, cnt = 1, tc = 0;
    for (ll i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            cnt++, tc++;
        }
        else
        {
            ans *= cnt;
            ans %= mod;
            cnt = 1;
        }
    }
    ans *= cnt, ans %= mod;
    ans *= fact[tc],ans %= mod;
    cout << tc << " " << ans << "\n";
}
int main()
{
    fastio;
    ll T = 1;
    cin >> T;
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    // cout<<fact[90]<<endl;a
    for (ll i = 1; i <= T; i++)
        solve();
    return 0;
}