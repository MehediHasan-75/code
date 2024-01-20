
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 2e5 + 10, inf = 2e18;
ll mod = 1000000007;
void solve(ll tc)
{
    cout << "Case " << tc << ": ";
    ll n;
    cin >> n;
    vector<ll> v1(n), v2(n);
    for (auto &it : v1)
        cin >> it;
    for (auto &it : v2)
        cin >> it;
    for (ll i = 0; i < n; i++)
    {
        xo ^= (v2[i] - v1[i] - 1);
    }
    if (xo == 0)
        cout << "black wins\n";
    else
        cout << "white wins\n";
}
int main()
{
    ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)
        solve(i);
    return 0;
}
