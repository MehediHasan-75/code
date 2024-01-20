#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
#define mod 1000000000
vector<ll>sz(N, 1), parent(N);
ll find_parent(ll u){
    return parent[u]==u? u: parent[u]=find_parent(parent[u]);
}
void Union(ll u, ll v){
    if(sz[u]<sz[v])swap(u, v);

    sz[u]+=sz[v];
    parent[v]=u;
}
struct Edge{
    ll u, v, w;
    bool operator <(Edge const& other){
        return w<other.w;
    }
};
int main(){
    ll n, m;
    cin>>n>>m;
    for(ll i=1; i<=n; i++)parent[i]=i;
    vector<Edge>edges;
    for(ll i=1; i<=m; i++){
        ll u, v, w;
        cin>>u>>v>>w;

        edges.push_back({u, v, w});
    }
    sort(edges.begin(), edges.end());

    // for(auto &it: edges){
    //     cout<<it.u<<" "<<it.v<<" "<<it.w<<endl;
    // }
    vector<ll>sum(m, 0);

    for(ll i=0; i<m; i++){
        sum[i]= (edges[i].w + (i>0? sum[i-1]:0))%mod;
    }
    // cout<<endl;
    // for(ll i=0; i<m; i++){
    //     cout<<sum[i]<<" ";
    // }
    ll ans=0;
    for(ll i=edges.size()-1; i>=0; i--){
        auto it=edges[i];

        ll u=it.u, v=it.v, w=it.w;
        u=find_parent(u), v=find_parent(v);

        if(u!=v){
            ans=(ans+sz[u]*sz[v]*sum[i])%mod;
            Union(u, v);
        }
    }
    cout<<(ans%mod)<<endl;
}