#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e4+10;

vector<pair<ll,ll>>graph[N];
ll level[N];
void dfs(ll u, ll parent){
    for(auto &v: graph[u]){
        if(v.first==parent)continue;

        level[v.first]= max(level[v.first], level[u]+ v.second);

        dfs(v.first, u);
    }
}
void solve(ll tc){

    cout<<"Case "<<tc<<": ";
    ll n;
    cin>>n;

    for(ll i=0; i<n; i++){
        graph[i].clear();
        level[i]=0;
    }
    for(ll i=0; i<n-1; i++){
        ll u, v, w;
        cin>>u>>v>>w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    level[1]=0;

    dfs(0, -1);

    ll mx=-1, nd=-1;
    for(ll i=0; i<n; i++){
        if(mx<level[i]){
            mx=level[i];
            nd=i;
        }
    }
    // cout<<nd<<endl;
    memset(level, 0, sizeof(level));
    dfs(nd, -1);
    mx=-1, nd=-1;
    // cout<<n<<endl;
    for(ll i=0; i<n; i++){
        // cout<<level[i]<<" ";
        if(mx<level[i]){
            mx=level[i];
            nd=i;
        }
    }
    cout<<mx<<endl;
}
int main(){
    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++)solve(i);
}