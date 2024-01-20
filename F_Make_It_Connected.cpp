#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define ll long long

vector<ll>parent(N), sz(N, 1);
ll find_parent(ll u){
    return parent[u]==u? u: parent[u]=find_parent(parent[u]);
}
ll Union(ll u, ll v){
    u=find_parent(u), v=find_parent(v);

    if(u==v)return 0;

    if(sz[u]<sz[v])swap(u, v);

    sz[u]+=sz[v];
    parent[v]=u;
    return 1;
}
int main(){
    ll n, m;
    cin>>n>>m;
    for(ll i=1; i<N; i++)parent[i]=i;

    vector<pair<ll, pair<ll,ll>>>edges;
    vector<pair<ll, ll>>cost(n);

    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        cost[i]={a, i+1};
    }
    sort(cost.begin(), cost.end());
    ll u=cost.front().second, c=cost.front().first;
    for(ll i=1; i<n; i++){
        ll v=cost[i].second, c1=cost[i].first;

        edges.push_back({c1+c,{u, v}});
    }
    for(ll i=0; i<m; i++){
        ll u, v, w;
        cin>>u>>v>>w;

        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());

    ll ans=0;
    for(auto &it: edges){
        ll c=it.first, u=it.second.first, v=it.second.second;

        if(Union(u, v))ans+=c;
    }
    cout<<ans<<endl;

}