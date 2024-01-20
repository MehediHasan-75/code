
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
    cin >> n >> m;

    vector<pair<ll,ll>> adj[n+10];
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> s(n);
    for(auto &it: s)cin>>it;

    vector<vector<ll>> dist(n, vector<ll>(1005, 1e17));
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;

    
    dist[0][1000] = 0;// here we came to city zero by usig bike with slowness 1000
    pq.push({0, 0, 1000});//cost, city, slowness.
    
    while(!pq.empty()){
        ll u=pq.top()[1], sln=min(pq.top()[2], s[u]), sl=pq.top()[2];
        pq.pop();

        for(auto &it: adj[u]){
            ll v=it.first, w=it.second;

            if(dist[v][sln]>dist[u][sl]+ w*sln){
                dist[v][sln]=dist[u][sl]+ w*sln;
                pq.push({dist[v][sln], v, sln});
            }
        }
    }
    ll a=1e18;

    for(ll i=0; i<=1000; i++)a=min(a, dist[n-1][i]);
    cout<<a<<endl;
    // cout<<"hi";
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    // cout<<T<<endl;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

