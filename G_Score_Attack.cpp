#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, inf=1e18;
vector<ll>dist(100000, -inf);
struct edges{
    ll u, v, w;
};
bool bellman(vector<edges>&Ed, ll source){
    dist[source]=0;
    for(ll i=0; i<n; i++){
        for(auto &[u, v, w]:Ed){
            if(dist[u]+w>dist[v]){
                dist[v]=dist[u]+w;
                if(v==n and i+1==n){
                    return false;
                }
            }
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    vector<edges>Ed(m);
    for(auto &it: Ed)cin>>it.u>>it.v>>it.w;

    if(bellman(Ed, 1))cout<<dist[n]<<endl;
    else cout<<"inf\n";
}