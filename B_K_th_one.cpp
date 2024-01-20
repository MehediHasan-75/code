#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
vector<ll>v(N), tree(N*4);
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
void update(ll node, ll st, ll en, ll ind){
    if(st==en){
        tree[node]=(!v[ind]);
        v[ind]=(!v[ind]);
        return;
    }
    ll mid=(st+en)>>1;
    if(ind<=mid){
        update(2*node, st, mid, ind);
    }
    else update(2*node+1, mid+1, en, ind);
    tree[node]=tree[2*node]+tree[2*node+1];
}
ll query(ll node, ll st, ll en, ll k) {
    if (k > tree[node])
        return -1;
    if (st==en)
        return st;
    int mid=(st+en)>>1;
    if (tree[node*2] > k)
        return query(node*2, st, mid, k);
    else 
        return query(node*2+1, mid+1, en, k - tree[node*2]);
}
int main(){
    ll n, m;
    cin>>n>>m;
    for(ll i=0; i<n; i++)cin>>v[i];
    build(1, 0, n-1);
    //for(ll i=0; i<10; i++)cout<<tree[i]<<" ";
    cout<<endl;
    while(m--){
        ll type;
        cin>>type;
        if(type==1){
            ll ind;
            cin>>ind;
            update(1, 0, n-1, ind);
            //for(ll i=0; i<10; i++)cout<<tree[i]<<" ";
            //cout<<endl;
        }
        else{
            ll k;
            cin>>k;
            // cout<<k<<" ";
            cout<<query(1, 0, n-1, k)<<endl;
        }
    }
}