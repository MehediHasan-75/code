#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define ll long long
vector<pair<ll,ll>>graph[N];
vector<ll>dist(N, 1e18);
void dijkstra(ll source){
    set<pair<ll,ll>>st;
    dist[source]=0;
    st.insert({source, 0});
    while(st.size()){
        auto it=st.begin();
        ll u=(*it).first, w=(*it).second;
        st.erase(st.begin());
        for(auto &it: graph[u]){
            ll v=it.first, w=it.second;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                st.insert({v, dist[v]});
            }
        }
    }
}
void clear(){
    for(ll i=0; i<N; i++)graph[i].clear(), dist[i]=1e18;
}
void solve(ll tc){
    clear();
    cout<<"Case "<<tc<<": ";
    ll n, m;
    cin>>n>>m;
    for(ll i=1; i<=m; i++){
        ll u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    dijkstra(1);
    if(dist[n]==1e18)cout<<"Impossible\n";
    else cout<<dist[n]<<endl;
}
int main(){
    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++)solve(i);
}
