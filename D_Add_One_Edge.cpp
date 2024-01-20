
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 3e5 + 10, inf=2e18;
vector<ll>graph[N];
ll n1, n2 , e;
void input_graph()
{
    cin>>n1>>n2>>e;
    for(ll i=0; i<e; i++)
    {
        ll a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}
bool vis[N];
ll parnt[N], level[N], mx;
void bfs(ll source)
{
    queue<ll>qu;
    qu.push(source);
    parnt[source]=-1;
    level[source]=0;
    vis[source]=1;
    while(!qu.empty())
    {
        ll parent=qu.front();
        qu.pop();
        for(auto &child: graph[parent])
        {
            if(vis[child])continue;
            qu.push(child);
            vis[child]=1;
            level[child]=level[parent]+1;
            mx=max(level[child], mx);
            parnt[child]=parent;
        }
    }
}
void solve(ll tc)
{
  input_graph();
  bfs(1);
  ll ans=0;
  ans+=mx;
  mx=0;
  //cout<<cnt<<endl;
  bfs(n2+n1);
  cout<<ans+mx+1<<endl;
  
}
int main()
{
    fastio;ll T = 1;
    //cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

