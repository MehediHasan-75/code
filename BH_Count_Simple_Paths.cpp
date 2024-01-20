#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
vector<ll>graph[N];
bool vis[N];
ll v, e, cnt=0;
void dfs(ll u){
    cnt++;
    vis[u]=1;
    if(cnt>1000000)return;
    for(auto &v: graph[u]){
        if(!vis[v]){
            dfs(v);
            vis[v]=0;
        }
    }
}
int main(){
    cin>>v>>e;
    for(ll i=0; i<e; i++){
        ll x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1);
    cout<<min(cnt, 1000000ll)<<endl;
}