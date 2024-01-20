#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=2e5+10, Log=21;
vector<ll>graph[mxN], depth(mxN, 0), sum(mxN, 0);
vector<vector<ll>>up(mxN, vector<ll>(Log, 1));

ll n;

void dfs(ll u, ll par){
    // cout<<u<<" ";
    for(auto &v: graph[u]){
        if(v==par)continue;
        depth[v]=depth[u]+1;
        up[v][0]=u;
        for(int j=1; j<Log; j++){
            up[v][j]=up[up[v][j-1]][j-1];
        }
        dfs(v, u);
    }
}
void dfs1(ll u, ll par){
    // cout<<u<<" ";
    for(auto &v: graph[u]){
        if(v==par)continue;
        dfs1(v, u);
        sum[u]+=sum[v];
    }
    // cout<<sm<<endl;
    // sum[u]=sm;
}
int get_lca(int u, int v){
    if(depth[u]<depth[v])swap(u, v);
    ll k=depth[u]-depth[v];
    for(ll j=Log-1; j>=0; j--){
        if(k&(1<<j)){
            u=up[u][j];
        }
    }
    if(u==v){
        return u;
    }
    for(ll j=Log-1; j>=0; j--){
        if(up[u][j]!= up[v][j]){
            u= up[u][j];
            v= up[v][j];
        }
    }
    return up[u][0];

}
int main(){
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin>>n>>m;

    for(ll i=0; i<n-1; i++){
        ll u, v;
        cin>>u>>v;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    dfs(1, 1);
    for(ll i=0; i<m; i++){
        ll u, v;
        cin>>u>>v;
        // cout<<u<<" "<<v<<endl;
        sum[u]++, sum[v]++;
        ll lca=get_lca(u, v);
        // cout<<lca<<endl;
        v=up[lca][0];
        if(v!=lca)sum[v]--;
        sum[lca]--;
    }
    dfs1(1, 1);
    for(ll i=1; i<=n; i++)cout<<sum[i]<<" ";
}