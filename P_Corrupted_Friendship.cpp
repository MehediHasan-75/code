#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
vector<ll>graph[N], depth(N, 0), sz(N, 0);
ll ans1, ans2, n;

void dfs(ll u, ll par){

    for(auto &v: graph[u]){
        if(v==par)continue;
        depth[v]=depth[u]+1;
        dfs(v, u);
        ans1++;
        sz[u]+=sz[v]+1;
    }
    ans2+=(n-sz[u]-depth[u]-1);
    // cout<<u<<" "<<sz[u]+depth[u]<<endl;
}   
void solve(ll tc){
    cout<<"Case "<<tc<<": ";
    ans1=ans2=0;
    cin>>n;

    for(ll i=0; i<n-1; i++){
        ll u, v;
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    depth[1]=0;
    dfs(1, -1);
    cout<<ans1<<" "<<ans2/2<<endl;
    for(ll i=1; i<=n; i++){
        graph[i].clear();
        depth[i]=sz[i]=0;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++)solve(i);
}