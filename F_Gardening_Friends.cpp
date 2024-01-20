
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

typedef long long ll;

const ll N = 2e5 + 10;
vector<ll>graph[N];
bool vis[N];
ll n, k, c;

void input_graph()
{
    cin>>n>>k>>c;
    for(ll i=0; i<=n; i++){
        graph[i].clear();
    }
    for(ll i=0; i<n-1; i++)
    {
        ll a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

ll cost[N];

void dfs(ll u, ll par){
    for(auto &v: graph[u]){
        if(v==par)continue;
        cost[v]=max(cost[u]+k, cost[v]);
        dfs(v, u);
    }
}
void solve(ll tc)
{
    input_graph();
    // cout<<n<<" "<<k<<" "<<c<<endl;
    memset(cost, 0, sizeof(cost));
    dfs(1, -1);
    ll mx=0, st=-1;

    ll change_cost[N];
    for(ll i=1; i<=n; i++){
        change_cost[i]=(cost[i]/k) *c;

        if(cost[i]>mx){
            mx=cost[i];
            st=i;
        }
    }
    // cout<<st<<" ";
    memset(cost, 0, sizeof(cost));
    dfs(st, -1);

    mx=0, st=-1;
    ll cost1[N];
    for(ll i=1; i<=n; i++){
        cost1[i]=cost[i];

        if(cost[i]>mx){
            mx=cost[i];
            st=i;
        }
    }
    dfs(st, -1);

    // for(ll i=1; i<=n; i++){
    //     cost[i]=max(cost[i], cost1[i]);
    //     // cout<<cost[i]<<" "<<cost1[i]<<endl;
    // }
    mx=0;
    for(ll i=1; i<=n; i++){
        mx=max(mx, cost[i]-change_cost[i]);
    }
    cout<<mx<<endl;

}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

