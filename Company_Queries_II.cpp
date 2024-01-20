#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=2e5+10, Log=21;
vector<ll>graph[mxN], depth(mxN, 0);
vector<vector<ll>>up(mxN, vector<ll>(Log, 0));

ll n;

void dfs(ll u){
    for(auto &v: graph[u]){
        depth[v]=depth[u]+1;
        up[v][0]=u;
        for(int j=1; j<Log; j++){
            up[v][j]=up[up[v][j-1]][j-1];
        }
        dfs(v);
    }
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
    ll q;
    cin>>n>>q;
    for(ll i=2; i<=n; i++){
        ll u=i, v;
        cin>>v;
        // cout<<u<<" "<<v<<endl;
        graph[v].push_back(u);
    }
    // ancestor[1][0]=1;
    dfs(1);

    while(q--){
        ll u, v;
        cin>>u>>v;
        cout<<get_lca(u, v)<<"\n";
    }
}