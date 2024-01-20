#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N=2e5+10;
vector<ll>graph[N], sz(N, 1);

void dfs1(ll u, ll par){
    for(auto &v: graph[u]){
        if(v==par)continue;

        dfs1(v, u);
        sz[u]+=sz[v];
    }
}
ll n;
vector<ll>v;
ll dfs2(ll u, ll par){
    // cout<<u<<" ";
    for(auto &v: graph[u]){
        if(v==par)continue;
        // cout<<sz[u]<<endl;
        if(sz[v]>n/2) return dfs2(v, u);
    }
    return u;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(ll i=0; i<n-1; i++){
        ll u, v;
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs1(1, -1);
    // for(ll i=1; i<=n; i++)cout<<sz[i]<<" ";
    // cout<<endl;
    ll p=dfs2(1, -1);
    cout<<p<<endl;
}