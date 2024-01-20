#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
vector<ll>graph[N];
ll color[N], v, e, fl=1, on, tw;
void dfs(ll u){
    for(auto &v: graph[u]){
        if(color[v]==0){
            if(color[u]==1){
                tw++;
                color[v]=2;
            }
            else {
                on++;
                color[v]=1;
            }
            dfs(v);
        }
        else{
            if(color[v]==color[u]){
                fl=0;
            }
        }
    }
}
int main(){
    cin>>v>>e;
    for(ll i=0; i<e; i++){
        ll x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    ll ans=v*(v-1)/2-e;
    for(ll i=1; i<=v; i++){
        if(color[i]==0){
            on=1, tw=0;
            color[i]=1;
            dfs(i);
            ans-=((on*(on-1)/2)+(tw*(tw-1))/2);
        }
    }
    if(!fl)cout<<0<<endl;
    else{
        cout<<ans<<endl;
    }
    //cout<<fl<<" "<<on<<" "<<tw<<endl;
}