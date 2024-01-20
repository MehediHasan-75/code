#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
vector<ll>graph[N], vis(N, 0);
bool fl=false;

void dfs(ll u, ll parent){

    vis[u]=1;
    for(auto &v: graph[u]){
        if(v==parent)continue;
        if(vis[v]){
            fl=false;
            return;
        }
        dfs(v, u);
    }
}
int main(){
    ll n, m;
    cin>>n>>m;

    for(ll i=0; i<m; i++){
        ll u, v;
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if(n-1!=m){
        cout << "NO\n";
        return 0;
    }

    dfs(1, -1);
    if(fl){
        cout << "NO\n";
        return 0;
    }

    for(ll i=1; i<=n; i++){
        if(!vis[i]){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}