
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
#define N 205
vector<ll>graph[N];
ll vis[N];
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
void clear(){
    for(ll i=0; i<N; i++){
        graph[i].clear();
    }
}
void solve(ll tc)
{
    input_graph();
    ll x, y;
    for(ll i=1; i<=v; i++){
        if(graph[i].size()==1)continue;
        else{
            ll mi=INT64_MAX;
            for(auto &it: graph[i])mi=min((ll)graph[it].size(), mi);
            if(mi==1)y=i;
            else x=i;
        }
    }
    cout<<graph[x].size()<<" "<<graph[y].size()-1<<endl;
    clear();
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

