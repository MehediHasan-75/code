#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
vector<ll>parent(N), sz(N, 1);
ll cnt=0;

ll find_parent(ll u){
   return parent[u]==u? u: parent[u]=find_parent(parent[u]);
}
void Union(ll u, ll v){
    u=find_parent(u), v=find_parent(v);
    ll n1=sz[u], n2=sz[v];
    cnt-=(n1*(n1-1)/2);
    cnt-=(n2*(n2-1)/2);

    if(sz[u]<sz[v])swap(u, v);

    parent[v]=u;
    sz[u]+=sz[v];

    ll n=sz[u];

    cnt+=(n*(n-1))/2;
}
vector<pair<ll, pair<ll,ll> > > edges;
int main(){

    for(ll i=1; i<N; i++)parent[i]=i;
    ll n, m;
    cin>>n>>m;
    for(ll i=0; i<n-1; i++){
        ll u, v, w;
        cin>>u>>v>>w;

        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());
    vector<pair<ll, ll>>queries(m);
    vector<ll>ans(m);

    for(ll i=0; i<m; i++){
        cin>>queries[i].first;
        queries[i].second=i;
    }
    sort(queries.begin(), queries.end());

    int pos = 0;//pos stores the index of the last added edge 
    //from the edge list
    for (int i = 0;i<m;i++){
        for (;pos < n - 1;pos++){
            ll u=edges[pos].second.first, v=edges[pos].second.second, w=edges[pos].first;

            if (w<=queries[i].first){
                Union(u, v);
            }
            else break;//because the edges are sorted in increasing order
        }
        ans[queries[i].second] = cnt;//queries[i][1] stores the index of the ith query
    }
    for(ll i=0; i<m; i++)cout<<ans[i]<<" ";
    cout<<endl;
}