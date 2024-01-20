
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
ll n, k, cost[N],vis[N];
vector<ll>graph[N];
void dfs(ll u){
    if(vis[u])return;
    vis[u]=1;
    bool has_no_child=true;
    ll sum=0;
    for(auto &it: graph[u]){
        has_no_child=false;
        dfs(it);
        sum+=cost[it];
    }
    if(has_no_child)sum=INT64_MAX;
   // cout<<"sum = "<<sum<<" "<<"node = "<<u<<endl;
    cost[u]=min(sum, cost[u]);
}
void clear(ll n){
    for(ll i=0; i<=n; i++){
        vis[i]=0;
        graph[i].clear();
    }
}
void solve(ll tc)
{ 
    cin>>n>>k;
    clear(n);
    for(ll i=1; i<=n; i++){
        cin>>cost[i];
    }
    for(ll i=1; i<=k; i++){
        ll free_ind;
        cin>>free_ind;
        cost[free_ind]=0;
    }
    // for(ll i=1; i<=n; i++)cout<<cost[i]<<" ";
    // cout<<endl;
    for(ll i=1; i<=n; i++){
        ll m;
        cin>>m;
        for(ll j=0; j<m; j++){
            ll v;
            cin>>v;
            graph[i].push_back(v);
        }
    }
    for(ll i=1; i<=n; i++){
        if(!vis[i])dfs(i);
    }
    for(ll i=1; i<=n; i++)cout<<cost[i]<<" ";
    cout<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

