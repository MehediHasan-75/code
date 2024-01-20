
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
    ll n;
    cin >> n;
    map<ll, ll> mp1, mp2,mp3;
    for (ll i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        mp1[i] = x;
        mp2[i] = y;
    }
    vector<ll> v;
    ll c = 1;
    for (ll i = 1; i <= n; i++)
    {
        ll x = mp1[c], y = mp2[c];
        // cout<<x<<"|"<<y<<" ";
        if (mp1[x] == y || mp2[x] == y)
        {
            if(mp3[x]==0){c = x;v.push_back(x);mp3[x]=1;}
            else{
                c=y;
                v.push_back(y);
                mp3[c]=1;
            }
        }
        else
        {
            c = y;
            v.push_back(y);
        }
    }
    for (auto it : v)
        cout << it << " ";
    cout << endl;
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
