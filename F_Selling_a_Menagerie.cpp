#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define ll long long
bool fl=0;
vector<ll>graph[N], cost(N);
ll vis[N];

void reset(ll n){
    for(ll i=1; i<=n; i++)graph[i].clear(), vis[i]=0;
    fl=0;
}
void solve(){
    ll n;
    cin>>n;

    reset(n);
    vector<ll>in(n+1, 0), parent(n+1);
    for(ll u=1; u<=n; u++){
        ll v;
        cin>>v;
        parent[u]=v;
        graph[u].push_back(v);
        in[v]++;
    }
    queue<ll>qu;
    for(ll i=1; i<=n; i++){
        cin>>cost[i];
        if(in[i]==0)qu.push(i);
    }
    vector<ll>vis(n+1, 0);
    while(qu.size()){
        ll now=qu.front();
        qu.pop();
        vis[now]=1;
        cout<<now<<" ";

        for(auto &v: graph[now]){
            in[v]--;
            if(in[v]==0)qu.push(v);
        }
    }
    for(ll i=1; i<=n; i++){
        if(!vis[i]){
            pair<ll,ll>p={cost[i], i};
            for(ll j=parent[i]; j!=i; j=parent[j]){
                if(p.first>cost[j])p={cost[j], j};
            }
            vis[p.second]=1;
            for(ll j=parent[p.second]; j!=p.second; j=parent[j]){
                cout<<j<<" ";
                vis[j]=1;
            }
            cout<<p.second<<" ";
        }
    }
    cout<<endl;
}
int main(){
    ll t;
    cin>>t;
    while(t--)solve();
}