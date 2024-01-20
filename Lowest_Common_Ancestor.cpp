#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=2e5+10, Log=20;// Log=log2(2*10^5)
vector<ll>graph[mxN], depth(mxN, 0);
vector<vector<ll>>up(mxN, vector<ll>(Log, 0));// up[u][j]=2^jth anchestor of u.
void dfs(ll u){
    for(auto &v: graph[u]){
        depth[v]=depth[u]+1;
        up[v][0]=u;
        for(int j=1; j<Log; j++){
            up[v][j]=up[up[v][j-1]][j-1];// up[v][4=2^4=16]= 8th anchestor of 8th ancgestor node.=up[v][3=2^3=8]
        }
        dfs(v);
    }
}
int get_lca(int u, int v){
    if(depth[u]<depth[v])swap(u, v);
    ll k=depth[u]-depth[v];// for maintaining same height of u and v from anchestor.
    //we need to move u to it's kth anchestor.
    for(ll j=Log-1; j>=0; j--){
        if(k&(1<<j)){// if set then we need to jump
            u=up[u][j];
        }
    }
    if(u==v){// if u or v is anchestor of it self
        return u;
    }
    for(ll j=Log-1; j>=0; j--){// finding previous node of anchestor of u and v
        if(up[u][j]!= up[v][j]){
            u= up[u][j];
            v= up[v][j];
        }
    }
    return up[u][0];// up 2^0=1 move for anchestor

}
int main(){
    ll n;
    cin>>n;
    for(ll i=0; i<n; i++){
        ll cnt;
        cin>>cnt;
        for(ll j=0; j<cnt; j++){
            ll child;
            cin>>child;
            graph[i].push_back(child);
        }
    }
    dfs(0);
    int q;
    cin>>q;
    while(q--){
        ll u, v;
        cin>>u>>v;
        cout<<get_lca(u, v)<<'\n';
    }
    // cout<<up[0][13]<<endl;
}