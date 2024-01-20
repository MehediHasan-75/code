#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
#define ll long long

vector<ll>parent(N), sz(N, 0);
ll find_parent(ll u){
    return parent[u]==u? u:parent[u]=find_parent(parent[u]);
}
ll cnt=0;
void Union(ll u, ll v){
    u=find_parent(u), v=find_parent(v);
    // cout<<u<<" "<<v<<endl;
    if(u==v){
        cnt++;
        return;
    }
    if(sz[u]<sz[v])swap(u, v);

    sz[u]+=sz[v];
    parent[v]=u;
}
int main(){
    ll n, m;
    cin>>n>>m;

    for(ll i=1; i<=n; i++)parent[i]=i, sz[i]=1;

    while(m--){
        ll u, v;
        cin>>u>>v;
        Union(u, v);
        vector<ll>vc;
        for(ll i=1; i<=n; i++){
            if(parent[i]==i){
                vc.push_back(sz[i]);
            }
        }
        sort(vc.begin(), vc.end(), greater<ll>());
        // for(ll i=0; i<vc.size(); i++)cout<<vc[i]<<" ";
        // cout<<endl;
        // cout<<cnt<<endl;
        ll ans=-1;
        for(ll i=0; i<=cnt; i++){
            ans+=vc[i];
        }
        cout<<ans<<endl;
    }
}