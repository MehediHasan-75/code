
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 2e5 + 10, inf=2e18;
vector<ll>graph[N], level(N, inf), source;
ll v, e;
void input_graph()
{
    for(ll i=0; i<e; i++)
    {
        ll a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}
void reset(){
    for(int i=0; i<N; i++){
        graph[i].clear();
        level[i]=inf;
    }
}
bool vis[N];
bool bfs(ll source, ll mx_level){
    level[source]=0;
    vis[source]=1;
    queue<ll>qu;
    qu.push(source);
    while(qu.size()){
        ll u=qu.front();
        qu.pop();
        if(level[u]==mx_level)continue;
        for(auto &v: graph[u]){
            if(vis[v])continue;
            if(level[v]!=inf)return false;
            level[v]=level[u]+1;
            qu.push(v);
            vis[v]=1;
        }
    }
    return true;
}
void solve(ll tc)
{
    reset();
    ll n, r, k;
    cin>>n>>r>>k;
    v=n, e=r;
    input_graph();
    bool fl=true;
    for(int i=0; i<k; i++){
        memset(vis, 0, sizeof(vis));
        ll source, mx_level;
        cin>>source>>mx_level;
        fl&=bfs(source, mx_level);
    }
    if(fl)cout<<"Yes\n";
    else cout<<"No\n";

}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

