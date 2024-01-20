#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10, Log=20;
vector<ll>graph[N], level(N, 0);
ll n, ancestor[N][Log+1];

void dfs(ll u, ll par){
    // cout<<u<<" ";
    for(auto &v: graph[u]){
        if(v==par)continue;
        level[v]=level[u]+1;
        ancestor[v][0]=u;

        for(ll i=1; i<=Log; i++){
            ancestor[v][i]=ancestor[ ancestor[v][i-1] ][i-1];
        }
        dfs(v, u);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    ll q;
    cin>>n>>q;
    for(ll i=1; i<n; i++){
        ll j;
        cin>>j;
        j--;
        graph[i].push_back(j);
        graph[j].push_back(i);
    }
    dfs(0, 0);
    while(q--){
        ll v, k;
        cin>>v>>k;
        v--;
        // cout<<v<<" "<<k<<endl;
        if(level[v]<k){
            cout<<-1<<endl;
        }
        else{
            for(ll i=0; i<=Log; i++){
                if((k&(1<<i))){
                    v=ancestor[v][i];
                }
            }
            cout<<v+1<<endl;
        }
    }
}