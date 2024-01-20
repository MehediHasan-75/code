#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=2e5+10;
vector<ll>graph[N];
ll level[N], par[N];
void dfs(ll u, ll parent){
    // cout<<u<<endl;
    for(auto &v: graph[u]){
        if(v==parent)continue;
        par[v]=u;
        level[v]=level[u]+1;
        dfs(v, u);
        // level[u]=max(level[v]+1, level[u]);
    }
}

ll vis[N], level2[N];
void dfs1(ll u, ll parent){
    for(auto &v: graph[u]){
        if(v==parent)continue;

        if(!vis[v])level2[v]=level2[u]+1;
        dfs1(v, u);
    }
}

int main(){
    ll n, ans=0;
    cin>>n;

    for(ll i=0; i<n-1; i++){
        ll u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ll mx=-1, ind=-1;
    // level[1]=0;
    dfs(1, -1);
    for(ll i=1; i<=n; i++){
        if(mx<level[i]){
            mx=level[i];
            ind=i;
        }
    }
    ll a=ind;
    memset(level, 0, sizeof(level));
    memset(par, -1, sizeof(par));
    dfs(ind, -1);
    mx=-1;
    for(ll i=1; i<=n; i++){
        if(mx<level[i]){
            mx=level[i];
            ind=i;
        }
    }
    ans+=mx;
    ll b=ind;
    ll p=b;
    // for(ll i=1; i<n; i++)cout<<level[i]<<" ";
    // cout<<endl;
    vector<ll>v;
    v.push_back(b);
    while(a!=p){
        // cout<<p<<" ";
        // ll p_=p;
        p=par[p];
        v.push_back(p);
        // cout<<p_<<" "<<p<<" "<<level[p]<<" ";
        // level[p_]-=level[p];
        // cout<<level[p_]<<endl;
    }
    reverse(v.begin(), v.end());

    // for(ll i=1; i<=v.size(); i++)level[v[i]]-=level[v[i-1]];

    // for(ll i=1; i<n; i++)cout<<level[i]<<" ";
    // cout<<endl;

    for(auto &it: v)vis[it]=1, level2[it]=0;
    // cout<<endl;
    dfs1(a, -1);
    // cout<<endl;

    // for(ll i=1; i<=n; i++)cout<<level2[i]<<" ";
    // cout<<endl;
    mx=-1;
    for(ll i=1; i<=n; i++){
        if(mx<level2[i] and i!=a and i!=b){
            mx=level2[i];
            ind=i;
        }
    }
    ans+=mx;
    ll c=ind;
    cout<<ans<<endl;
    cout<<a<<" "<<b<<" "<<c<<endl;
}