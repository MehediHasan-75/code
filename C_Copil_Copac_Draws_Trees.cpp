
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
ll mod = 1000000007, cnt = 0;
vector<ll> graph[N];
vector<ll> val(N, 0);
map<pair<ll, ll>, ll> mp;
void dfs(ll parent, ll prev, ll prev_num)
{

    for (auto &it : graph[parent])
    {

        if (it == prev)
            continue;

        ll now = mp[{parent, it}];
        if (parent == 1)
            val[it] = 1;
        if (now < prev_num)
            val[it] = val[parent] + 1;
        else
            val[it] = val[parent];
        dfs(it, parent, now);
    }
}
void reset()
{
    cnt = 0;
    mp.clear();
    for (ll i = 1; i < N; i++)
        graph[i].clear();
    val.clear();
}
void solve(ll tc)
{
    ll v;
    cin >> v;
    for (ll i = 0; i < v - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        mp[{a, b}] = i;
        mp[{b, a}] = i;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, -1, INT64_MAX);
    ll mx=0;
    for(ll i=1; i<=v; i++)mx=max(mx, val[i]);
    cout<<mx<<endl;
    reset();
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
