#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    ll n, m, q;
    cin>>n>>m>>q;

    vector<vector<ll>>adj(n, vector<ll>(n, 1e18));
    
    for(ll i=0; i<m; i++){
        ll a, b, c;
        cin>>a>>b>>c;
        a--, b--;
        adj[a][b]=adj[b][a]=min(adj[a][b],c);
    }
    for(ll i=0; i<n; i++)adj[i][i]=0;

    for(ll k=0; k<n; k++)
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
        }
    }
    while(q--){
        ll u, v;
        cin>>u>>v;
        u--, v--;
        cout<<(adj[u][v]==1e18? -1: adj[u][v])<<"\n";
    }
}