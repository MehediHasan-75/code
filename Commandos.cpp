#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=101;

vector<ll>graph[N];
ll level[N], vis[N];

void bfs(ll source){
    level[source]=0;
    vis[source]=1;

    queue<ll>qu;
    qu.push(source);

    while(qu.size()){
        ll u=qu.front();
        qu.pop();

        for(auto &v: graph[u]){
            if(vis[v])continue;
            vis[v]=1;
            qu.push(v);
            level[v]=level[u]+1;
        }
    }
}
void solve(ll tc){
    cout<<"Case "<<tc<<": ";
    ll n, m;
    cin>>n>>m;
    for(ll i=0; i<n; i++)graph[i].clear();
    for(ll i=0; i<m; i++){
        ll u, v;
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ll s, t;
    cin>>s>>t;
    // cout<<s<<" "<<t<<endl;
    memset(vis, 0, sizeof(vis));
    memset(level, 0, sizeof(level));
    bfs(s);
    ll mx=-1, ind=-1, level1[n];

    for(ll i=0; i<n; i++){
        if(mx<level[i]){
            mx=level[i];
            ind=i;
        }
        level1[i]=level[i];
    }
    ll ans=mx;

    memset(vis, 0, sizeof(vis));
    memset(level, 0, sizeof(level));
    bfs(t);

    // cout<<level[t]<<endl;
    mx=0;
    for(ll i=0; i<n; i++){
        mx=max(mx, level[i]+level1[i]);
    }
    cout<<mx<<endl;
}
int main(){
    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++){
        solve(i);
    }
}