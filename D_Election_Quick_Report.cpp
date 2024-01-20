
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

class compare {
public:
    bool operator()(pair<ll,ll> p1, pair<ll,ll> p2)
    {
        if (p1.first != p2.first) {
            return p1.first < p2.first;
        }

        return p1.second>p2.second;
    }
};

void solve(ll tc)
{
    ll n, m;
    cin>>n>>m;
    map<ll,ll>mp;

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, compare>pq;

    for(ll i=1; i<=m; i++){
        ll a;
        cin>>a;
        mp[a]++;
        // cout<<mp[a]<<" ";
        pq.push({mp[a], a});
        cout<<pq.top().second<<"\n";
    }
}
int main()
{
    fastio;ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

