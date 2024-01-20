#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=301;
ll adj[N][N], n;

ll update(ll u, ll v, ll cost){
    // cout<<u<<" "<<v<<" "<<cost<<endl;
    adj[u][v]=adj[v][u]=min(cost, adj[u][v]);
    ll sum=0;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            adj[i][j]=min(adj[i][j], adj[i][u]+adj[u][v]+adj[v][j]);
            adj[i][j]=min(adj[i][j], adj[i][v]+adj[v][u]+adj[u][j]);
            sum+=adj[i][j];
        }
    }
    return sum/2;
}
int main(){
    cin>>n;

    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cin>>adj[i][j];
        }
    }
    ll q;
    cin>>q;
    while(q--){
        ll u, v, cost;
        cin>>u>>v>>cost;
        u--, v--;
        cout<<update(u, v, cost)<<" ";
    }
    cout<<endl;
}