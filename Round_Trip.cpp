#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
vector<ll>graph[N];
ll v, e, st, en;
vector<ll>ans, vis(N,0),par(N);
bool fl=false;
void dfs(ll node, ll p=-1){
    //cout<<node<<" "<<p<<endl;
    vis[node]=1;
    par[node]=p;
    for(auto &it: graph[node]){
        if(it==p)continue;
        if(vis[it]){
            st=node;
            en=it;
            fl=1;
            return;
        }
        if(!fl and !vis[it])dfs(it, node);
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
    for(ll i=1; i<=v; i++){
        if(!fl and !vis[i])dfs(i);
    }
    if(!fl){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    vector<ll>ans;
    ans.push_back(st);
    while(en!=st){
        ans.push_back(en);
        en=par[en];
    }
    ans.push_back(st);
    cout<<ans.size()<<"\n";
    for(auto &it: ans)cout<<it<<" ";
//    cout<<st<<" "<<en<<endl;
//    for(ll i=1; i<=v; i++)cout<<par[i]<<" ";
}