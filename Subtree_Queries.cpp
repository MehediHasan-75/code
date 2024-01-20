#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define ll long long
vector<ll>graph[N], tree(4*N, 0), v(N, 0), values(N, 0), start(N), sz(N, 0), nodes;
ll timer=1;
void build(ll node, ll st, ll en){
    if(st==en){
        tree[node]=v[st];
        return;
    }
    ll mid=(st+en)>>1;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    tree[node]=tree[2*node]+tree[2*node+1];
    return;
}
//query(1, 0, n-1, l, r);
ll query(ll node, ll st, ll en, ll l, ll r){
    if(st>r or en<l){
        return 0;//no overlap
    }
    if(l<=st and en<=r){
        return tree[node];//full overlap
    }
    ll mid=(st+en)>>1;
    ll left=query(2*node, st, mid, l, r);
    ll right=query(2*node+1, mid+1, en, l, r);
    return left+right;
}
//similar to binary search.
void update(ll node, ll st, ll en, ll ind, ll val){
    if(st==en){
        tree[node]=val;
        v[ind]=val;
        return;
    }
    ll mid=(st+en)>>1;
    if(ind<=mid){
        update(2*node, st, mid, ind, val);
    }
    else update(2*node+1, mid+1, en, ind, val);
    tree[node]=tree[2*node]+tree[2*node+1];
}


void dfs(ll u, ll par){
    start[u]= timer++;
    nodes.push_back(u);
    for(auto &v: graph[u]){
        if(v==par)continue;
        dfs(v, u);
        sz[u]+=sz[v]+1;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    ll n, q;
    cin>>n>>q;

    for(ll i=1; i<=n; i++){
        cin>>values[i];
    }
    for(ll i=1; i<n; i++){
        ll u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, -1);
    nodes.push_back(0);
    for(ll i=nodes.size()-1; i>0; i--){
        nodes[i]=nodes[i-1];
    }
    for(ll i=1; i<=n; i++){
        ll nd=nodes[i];
        v[i]=values[nd];
    }
    // for(ll i=1; i<=n; i++){
    //     cout<<v[i]<<" ";
    // }
    // for(ll i=1; i<=n; i++)cout<<nodes[i]<<" ";
    // cout<<endl;

    build(1, 1, n);
    // cout<<start[2]<<" "<<start[2]+sz[2]<<endl;
    // cout<<query(1, 1, n, start[2], start[2]+sz[2])<<endl;

    while(q--){
        ll type;
        cin>>type;
        if(type==2){
            ll node;
            cin>>node;
            cout<<query(1, 1, n, start[node], start[node]+sz[node])<<"\n";
        }
        else{
            ll node, val;
            cin>>node>>val;
            
            ll ind=start[node];
            update(1, 1, n, ind, val);
            // cout<<query(1, 1, n, 1, 1)<<endl;
        }
    }
}