
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
const ll N = 1e5 + 10, inf = 2e18;
ll mod = 1000000007;

/*Interval can be uniquely represented as a union of intervals with lengths that are decreasing powers of two
as ny non-negative number can be uniquely represented as a sum of decreasing powers of two*/
const int LOG = 31;
ll stable[LOG][N];
/*stable[i][j]= range[j, j+2^i-1];
 */
ll func(ll a, ll b)
{
    return min(a, b);
}
ll rangeMinQuery(ll l, ll r)
{
    ll len = r - l + 1, i = log2(len);
    // cout<<i<<endl;
    return min(stable[i][l], stable[i][r - (1 << i) + 1]);
}
ll rangeQuery(ll l, ll r)
{
    ll sum = 0;
    for (int i = LOG; i >= 0; i--)
    {
        if ((1 << i) <= r - l + 1)
        {
            sum += stable[i][l];
            l += 1 << i;
        }
    }
    return sum;
}
void spharseTable(vector<ll> &array)
{
    copy(array.begin(), array.end(), stable[0]); // storing information of stable[i][0] means original array
    for (ll i = 1; i < LOG; i++)
    {
        for (ll j = 0; j + (1ll << i) < N; j++)
        {
            stable[i][j] = func(stable[i - 1][j], stable[i - 1][j + (1 << (i - 1))]);
        }
    }
}
void solve(ll tc)
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];

    spharseTable(v);
    ll q;
    cin >> q;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        cout << rangeMinQuery(l, r) << endl;
    }
}
int main()
{
    fastio;
    ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)
        solve(i);
    return 0;
}
