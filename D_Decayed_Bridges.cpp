#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long 
ll parent[N], sz[N], cnt, node=0;
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
    // cout<<u<<" "<<v<<endl;
    // cout<<cnt<<" "<<sz[a]<<" "<<sz[b]<<endl;
    cnt-=sz[a]*sz[b];
    parent[a]=b;
    sz[b]+=sz[a];
    return true;
}
int main(){
    ll n, m;
    cin>>n>>m;
    make_set(n);
    cnt=(n*(n-1))/2;
    vector<ll>ans;
    vector<pair<ll,ll>>v(m);
    for(auto &it: v)cin>>it.first>>it.second;
    // reverse(v.begin(), v.end());
    ans.push_back(cnt);
    for(ll i=v.size()-1; i>0; i--){
        Union(v[i].first, v[i].second);
        ans.push_back(cnt);
    }
    reverse(ans.begin(), ans.end());
    for(auto &it: ans)cout<<it<<endl;
}