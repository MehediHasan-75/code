#include<bits/stdc++.h>
using namespace std;
#define N 10005
#define ll long long 
ll parent[N], sz[N];
void make_set(ll n){
    for(ll i=1; i<=n; i++){
        parent[i]=i;
        sz[i]=1;
    }
}
ll find_parent(ll u){
    if(u==parent[u])return u;
    return parent[u]=find_parent(parent[u]);
}
bool Union(ll u, ll v){
    ll a=find_parent(u), b=find_parent(v);
    if(a==b)return false;
    if(sz[a]>sz[b])swap(a, b);
    parent[a]=b;
    sz[b]+=sz[a];
    return true;
}
void solve(){
    ll n;
    cin>>n;
    make_set(n);
    vector<pair<ll,ll>>remv;
    map<ll,vector<ll>>mp;
    for(ll i=0; i<n-1; i++){
        ll u, v;
        cin>>u>>v;
        bool ok=Union(u, v);
        //cout<<u<<" "<<v<<endl;
        if(!ok)remv.push_back({u, v});
    }
    for(ll i=1; i<=n; i++){
        ll par=find_parent(i);
        mp[par].push_back(i);
    }
    vector<pair<ll,ll>>add;
    ll prev=mp.begin()->second.back();
    auto it=mp.begin();
    it++;
    for(; it!=mp.end(); it++){
        ll now=it->second.back();
        add.push_back({prev, now});
        prev=now;
    }
    ll nn=add.size();
    cout<<nn<<endl;
    for(ll i=0; i<nn; i++){
        cout<<remv[i].first<<" "<<remv[i].second<<" "<<add[i].first<<" "<<add[i].second<<endl;
    }
}
int main(){
    ll t=1;
    while(t--)solve();
}