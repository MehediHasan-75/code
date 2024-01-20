#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=5e4+10;
vector<ll>parent(N), sz(N);
ll n, m;
ll find_parent(ll u){
    return parent[u] ==u ?u: parent[u]=find_parent(parent[u]);
}
void Union(ll u, ll v, ll wt){

    u=find_parent(u), v=find_parent(v);
    if(u==v){
        return;
    }

    if(sz[u]<sz[v])swap(u, v);

    sz[u]+=sz[v];
    parent[v]=u;
}
struct Edge{
    ll u, v, w;
    bool operator <(Edge const& other){
        return w>other.w;
    }
};
void solve(ll tc){
    cin>>n>>m;
    for(ll i=1; i<=n; i++){
        parent[i]=i;
        sz[i]=0;
    }
    vector<Edge>edges(m);

    for(ll i=0; i<m; i++){
        ll u, v, w;
        cin>>u>>v>>w;
        edges[i]={u, v, w};
    }
    sort(edges.begin(), edges.end());
    for(ll i=0; i<m; i++){
        auto it=edges[i];
        Union(it.u, it.v, it.w);
        if(find_parent(1)==find_parent(n)){
            cout<<it.w<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++)solve(i);
}   