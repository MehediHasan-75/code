#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 501
ll capacity[N][N], n, m;
vector<ll>graph[N];
ll bfs(ll s, ll t, vector<ll>&parent){
    fill(parent.begin(), parent.end(), -1);
    parent[s]=-2;
    queue<pair<ll,ll>>qu;
    qu.push({s, INT64_MAX});
    while(qu.size()){
        ll cur=qu.front().first;
        ll cur_flow=qu.front().second;
        qu.pop();
        for(auto &next: graph[cur]){
            if(parent[next]==-1 and capacity[cur][next]){
                parent[next]=cur;
                ll new_flow=min(cur_flow, capacity[cur][next]);
                if(next==t)return new_flow;
                qu.push({next, new_flow});
            }
        }
    }
    return 0ll;
}
ll max_flow(ll s, ll t){
    ll flow=0, new_flow;
    vector<ll>parent(n+10);
    while(new_flow=bfs(s, t, parent)){
        flow+=new_flow;
        ll now=t;
        while(now!=s){
            ll prev=parent[now];
            capacity[prev][now]-=new_flow;
            capacity[now][prev]+=new_flow;
            now=prev;
        }
    }
    return flow;
}
int main(){
    cin>>n>>m;
    for(ll i=0; i<m; i++){
        ll x, y, w;
        cin>>x>>y>>w;
        graph[x].push_back(y);
        graph[y].push_back(x);
        capacity[x][y]+=w;
    }
    // for(ll i=1; i<=n; i++){
    //     for(ll j=1; j<=n; j++){
    //         cout<<i<<" "<<j<<" "<<capacity[i][j]<<endl;
    //     }
    // }
    cout<<max_flow(1ll,n)<<endl;
}