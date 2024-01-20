
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
vector<ll>graph[N];
bool vis[N];
ll v, e;
void input_graph()
{
    cin>>v>>e;
    for(ll i=0; i<e; i++)
    {
        ll a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}
bool flag=true;//if false not bicolorable
vector<ll>col(N,0);
void dfs(ll u, ll p=0){
    for(auto &v: graph[u]){
        if(v!=p){
            if(!vis[v]){
                col[v]=!col[u];
                vis[v]=true;
                dfs(v,u);
            }
            else{
                if(col[v]==col[u])flag=false;
            }
        }
    }
}
void solve(ll tc)
{
    input_graph();
    for(ll i=1; i<=v; i++){
        if(vis[i]==0){
            dfs(i, 0);
        }
    }
    if(!flag)cout<<"IMPOSSIBLE\n";
    else{
        for(ll i=1; i<=v; i++)cout<<col[i]+1<<" ";
    }
}
int main()
{
    fastio;ll T = 1;
    //cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

