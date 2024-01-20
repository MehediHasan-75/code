#include<bits/stdc++.h>
using namespace std;
const int N=105;
#define ll long long
vector <ll> graph[N];
ll color[N][3];
void dfs(int u,int col)
{      if(col!=-1)
       color[u][col]=1;

       int nextcol=1;
       if(col==1) nextcol=2;
       for(auto &v: graph[u]){
        if(!color[v][nextcol])dfs(v, nextcol);
       }
}
void solve(ll tc){
    cout<<"Case "<<tc<<": ";
    ll n, m;
    cin>>n>>m;

    for(ll i=0; i<m; i++){
        ll u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);
    ll ans=0;
    for(ll i=1; i<=n; i++)if(color[i][2])ans++;
    cout<<ans<<endl;
    for(ll i=1; i<=n; i++){
        graph[i].clear();
        color[i][0]=color[i][1]=color[i][2]=0;
    }
}

int main(){
    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++)solve(i);
}