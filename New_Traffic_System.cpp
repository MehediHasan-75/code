#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=4e4+10;
vector<vector<ll>>graph[N];
vector<vector<ll>>dist(150, vector<ll>(N, 1e18));
ll n, m, k, d;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void dijkstra(ll source){
    for(ll i=0; i<=d; i++){
        for(ll j=0; j<n; j++)dist[i][j]=1e18;
    }
    dist[0][source]=0;
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>> >pq;
    pq.push({0, 0, source});//wt, cnt, source;

    while(!pq.empty()){
        ll wt=pq.top()[0], cnt=pq.top()[1], u=pq.top()[2];
        pq.pop();

        if(dist[cnt][u]<wt) continue;

        for(auto &e: graph[u]){
            ll v=e[0], w=e[1], type=e[2];

            if(cnt+type<=d and dist[cnt][u]+w< dist[cnt+type][v]){
                dist[cnt+type][v] = dist[cnt][u] + w;
                pq.push ( { dist[cnt+type][v], cnt+type, v } );
            }
        }
    }
}
void solve(ll tc){
    cout<<"Case "<<tc<<": ";
    cin>>n>>m>>k>>d;
    for(ll i=0; i<n; i++)graph[i].clear();
    for(ll i=0; i<m; i++){
        ll u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w, 0});
    }
    for(ll i=0; i<k; i++){
        ll u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w, 1});
    }
    dijkstra(0);
    ll ans=1e18;
    for(ll i=0; i<=d; i++)ans=min(ans, dist[i][n-1]);
    if(ans==1e18)cout<<"Impossible\n";
    else cout<<ans<<"\n";
}
int main(){
    fastio;
    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++)solve(i);
}