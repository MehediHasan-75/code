#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
vector<ll>graph[N];
ll vis[N], level[N];
void dfs(ll u){
    vis[u]=1;
    for(auto &v: graph[u]){
        if(!vis[v]){
            level[v]=level[u]+1;
            dfs(v);
        }
    }
}
int main(){
    ll v;
    cin>>v;
    for(ll i=0; i<v-1; i++){
        ll x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1);
    ll mx=-1, st;
    for(ll i=1; i<=v; i++){
        if(level[i]>mx){
            mx=level[i];
            st=i;
        }
    }
    // cout<<st<<endl;
    memset(vis, 0, sizeof(vis));
    memset(level,0, sizeof(level));
    dfs(st);
    mx=-1;
    ll en=-1;
    for(ll i=1; i<=v; i++){
        if(level[i]>mx){
            mx=level[i];
            en=i;
        }
    }
    vector<ll>ans(v+1, 0);
    for(ll i=1; i<=v; i++){
        ans[i]=level[i];
    }
    memset(vis, 0, sizeof(vis));
    memset(level,0, sizeof(level));
    dfs(en);
    for(ll i=1; i<=v; i++){
        cout<<max(level[i], ans[i])<<" ";
    }
}