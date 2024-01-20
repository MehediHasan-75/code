#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define ll long long
vector<pair<ll,ll>>graph[N];
vector<pair<ll,ll>>dist(N, {1e18, 1e18});


void dijkstra(ll source){
    priority_queue<pair<ll,ll>>qu;
    dist[source]={0,0};
    qu.push({source, 0});
    while(qu.size()){
        auto it=qu.top();
        ll u=(it).first, w=(it).second;
        qu.pop();
        for(auto &it: graph[u]){
            ll v=it.first, w=it.second;
            if(dist[v].first>dist[u].first+w){
                dist[v].second=dist[v].first;
                dist[v].first=dist[u].first+w;
                qu.push({v, dist[v].first});
            }
            else if(dist[v].second> dist[u].first+w){
                dist[v].second=dist[u].first+w;
                // qu.push({v, dist[v].second});
            }
        }
    }
}
void clear(){
    for(ll i=0; i<N; i++)graph[i].clear(), dist[i]={1e18, 1e18};
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
    cout<<dist[n].second<<endl;
}
int main(){
    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++)solve(i);
}
