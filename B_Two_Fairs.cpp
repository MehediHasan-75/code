
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 5e5 + 10, inf=2e18;
ll mod = 1000000007;
vector<ll>graph[N];
bool vis[N];
ll v, e, x, y;
void input_graph()
{
    cin>>v>>e>>x>>y;
    for(ll i=0; i<=v; i++){
        vis[i]=0;
        graph[i].clear();
    }
    for(ll i=0; i<e; i++)
    {
        ll a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}
void dfs(ll u, ll x){
    vis[u]=1;
    for(auto &v: graph[u]){
        if(vis[v] or v== x)continue;
        dfs(v, x);
    }
}
void solve(ll tc)
{
    input_graph();
    dfs(x, y);
    set<ll>st1, st2;
    for(ll i=1; i<=v; i++){
        if(vis[i] and i!=x)st1.insert(i);
    }
    memset(vis, 0, sizeof(vis));
    dfs(y, x);

    for(ll i=1; i<=v; i++){
        if(i!=y and vis[i]){
            if(st1.find(i)!=st1.end())st1.erase(i);
            else st2.insert(i);
        }
    }
    ll ans=(ll)st1.size() *(ll)st2.size();
    cout<<ans<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

