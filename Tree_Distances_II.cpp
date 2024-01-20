#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll n;
vector<ll>graph[N], nodesCnt(N, 1), ansSubtree(N);

void dfs1(ll u, ll par){
    ll nodes=1, ans=0;
    for(auto &v: graph[u]){
        if(v==par)continue;
        dfs1(v, u);
        ans+=nodesCnt[v]+ansSubtree[v];
        nodes+=nodesCnt[v];
    }
    nodesCnt[u]=nodes;
    ansSubtree[u]=ans;
}
vector<ll>ans(N);

//re-rooting
void dfs2(ll u, ll par){
    ans[u]=ansSubtree[u];
    for(auto &v: graph[u]){
        if(v==par)continue;
        ansSubtree[u]-=ansSubtree[v]+nodesCnt[v];
        ansSubtree[v]+=(ansSubtree[u]+(n-nodesCnt[v]));
        dfs2(v, u);
        ansSubtree[v]-=(ansSubtree[u]+(n-nodesCnt[v]));
        ansSubtree[u]+=ansSubtree[v]+nodesCnt[v];
    }
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
    dfs2(1, -1);
    for(ll i=1; i<=n; i++){
        cout<<ans[i]<<" ";
    }
}