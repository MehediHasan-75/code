#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mxN=2e5+10, Log=20;
vector<ll>depth(mxN, 0);
vector<ll>graph[mxN];
vector<vector<ll>>up(mxN, vector<ll>(Log, 0));
void dfs(ll u, ll parent){
    for(auto &v: graph[u]){
        if(v==parent)continue;
        depth[v]=depth[u]+1;
        up[v][0]=u;
        for(int j=1; j<Log; j++){
            up[v][j]=up[up[v][j-1]][j-1];
        }
        dfs(v, u);
    }
}
pair<ll,ll>get_lca(ll u, ll v){
    if(depth[u]<depth[v])swap(u, v);
    ll k=depth[u]-depth[v];
    // cout<<k<<endl;
    for(ll j=Log-1; j>=0; j--){
        if(k&(1<<j)){
            u=up[u][j];
        }
    }
    // cout<<u<<" "<<v<<endl;
    if(u==v)return {u, 0};
    for(ll j=Log-1; j>=0; j--){
        if(up[u][j]!=up[v][j]){
            u=up[u][j];
            v=up[v][j];
        }
    }
    // cout<<u<<" "<<v<<endl;
    return {up[u][0], 1};
}
int main(){
    fastio;
    ll n, q;
    cin>>n>>q;
    for(ll i=0; i<n-1; i++){
        ll u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    up[1][0]=1;
    dfs(1, -1);
    // for(int i=1; i<=n; i++)cout<<depth[i]<<" ";
    while(q--){
        ll u, v;
        cin>>u>>v;
        // cout<<u<<" "<<v<<endl;
        depth[1]=0;
        pair<ll,ll> lca=get_lca(u, v);
        // cout<<u<<" "<<v<<endl;
        // cout<<lca.first<<endl;
        // cout<<lca.second<<endl;
        // cout<<depth[u]<<" "<<depth[v]<<endl;
        // depth[u]-lca +depth[v] -lca;
        if(lca.second)cout<<depth[u]+depth[v]-2*depth[lca.first]<<endl;
        else cout<<abs(depth[u]-depth[v])<<endl;
    }
}