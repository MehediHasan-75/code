#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
const int N=2e5+10;
vector<ll>graph[N];
ll dp[N][2];
ll dfs(ll u, ll par, ll taken){
    ll ans=0;
    if(dp[u][taken]!=-1){
        return dp[u][taken];
    }
    if(taken){
        for(auto &v: graph[u]){
            if(v==par)continue;
            ans+=dfs(v, u, 1);
        }
        ll mx=0;
        for(auto &v: graph[u]){
            if(v==par)continue;
            mx=max(mx, ans+1-dp[v][1]+dfs(v, u, 0));
        }
        ans=mx;
    }
    else{
        for(auto &v: graph[u]){
            if(v==par)continue;
            ans+=dfs(v, u, 1);
        }
    }
    return dp[u][taken]=ans;
}

int main(){
    ll n;
    cin>>n;
    memset(dp, -1, sizeof(dp));
    for(ll i=0; i<n-1; i++){
        ll u, v;
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout<<max(dfs(1, -1, 0), dfs(1, -1, 1))<<endl;
}