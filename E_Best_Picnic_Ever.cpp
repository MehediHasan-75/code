#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+10;
vector<ll>graph[N], cnt(N, 0);

void dfs(ll u, vector<bool>&vis){
    cnt[u]++;
    vis[u]=true;

    for(auto &v: graph[u]){
        if(vis[v])continue;
        dfs(v, vis);
    }
}
void solve(ll tc){
    cout<<"Case "<<tc<<": ";
    ll k, n, m;
    cin>>k>>n>>m;

    vector<ll>source(k);
    for(auto &it: source)cin>>it;

    for(ll i=0; i<m; i++){
        ll u, v;
        cin>>u>>v;

        graph[u].push_back(v);
    }
    for(ll i=0; i<k; i++){
        vector<bool>vis(n+10, false);
        dfs(source[i], vis);
    }

    ll ans=0;

    for(ll i=1; i<=n; i++){
        if(cnt[i]==k)ans++;
        cnt[i]=0;
    }
    cout<<ans<<endl;
    for(ll i=1; i<=n; i++)graph[i].clear();
}
int main(){
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++)solve(i);
}