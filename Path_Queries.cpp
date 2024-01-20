#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=2e5+10;
vector<ll>graph[N], start(N, 0), en(N), values(N), nodes;
ll timer=1;
void dfs(ll u, ll par){
    nodes.push_back(values[u]);
    start[u]=timer++;
    for(auto &v: graph[u]){
        if(v==par)continue;
        dfs(v, u);
    }
    en[u]=timer++;
    nodes.push_back(-values[u]);
}

vector<ll>tree(8*N);

void build(ll node, ll st, ll en){
    if(st==en){
        tree[node]=nodes[st];
        return;
    }
    ll mid=(st+en)>>1;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    tree[node]=tree[2*node]+tree[2*node+1];
    return;
}
ll query(ll node, ll st, ll en, ll l, ll r){
    // cout<<nodes[node]<<" "<<st<<" "<<en<<endl;
    // for(ll i=st; i<=en; i++)cout<<nodes[i]<<" ";
    // cout<<endl;
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
void update(ll node, ll st, ll en, ll ind, ll val){
    if(st==en){
        tree[node]=val;
        nodes[ind]=val;
        return;
    }
    ll mid=(st+en)>>1;
    if(ind<=mid){
        update(2*node, st, mid, ind, val);
    }
    else update(2*node+1, mid+1, en, ind, val);
    tree[node]=tree[2*node]+tree[2*node+1];
}
int main(){
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin>>n>>m;
    for(ll i=1; i<=n; i++)cin>>values[i];

    for(ll i=0; i<n-1; i++){
        ll u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, -1);
    nodes.push_back(0);
    for(ll i=nodes.size()-1; i>0; i--)nodes[i]=nodes[i-1];

    build(1, 1, 2*n);
    // for(auto &it: nodes)cout<<it<<" ";
    // cout<<endl;
    // cout<<tree[1]<<endl;
    while(m--){
        ll type;
        cin>>type;

        if(type==1){
            ll v, c;
            cin>>v>>c;

            update(1, 1, 2*n, start[v], c);
            update(1, 1, 2*n, en[v], -c);
        }
        else{
            ll u;
            cin>>u;
            // cout<<start[u]<<" "<<en[u]<<endl;
            cout<<query(1, 1, 2*n, 1, start[u])<<endl;
        }
    }
    // for(ll i=1; i<=4*n; i++)cout<<tree[i]<<" ";
    // cout<<endl;
    // for(auto &it: nodes)cout<<it<<" ";
    // cout<<endl;
    // for(ll i=1; i<=n; i++)cout<<start[i]<<" "<<en[i]<<endl;

}