#include<bits/stdc++.h>
using namespace std;
#define ll long long
pair<ll,ll>p;
void dfs(ll u, ll par, ll depth, auto graph){
    
    if(depth>p.first)p.first=depth, p.second=u;
    for(auto &v: graph[u]){
        if(v==par)continue;
        dfs(v, u, depth+1, graph);
    }
}
int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    ll n;
    cin>>n;
    ll ans=0;
    // cout<<n<<endl;
    for(ll i=0; i<n; i++){
        ll nd;
        cin>>nd;
        vector<ll>graph[nd+10];
        for(ll j=0; j<nd-1; j++){
            ll u, v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        p={0, 1};
        dfs(1, -1, 0, graph);
        ll u=p.second;
        p={0, u};
        dfs(u, -1, 0, graph);
        ans+=p.first;
        // cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<ans<<endl;
}