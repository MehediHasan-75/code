#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
vector<ll>tree(4*N), v(N);
ll build(ll node, ll st, ll en){
    if(st==en){
        tree[node]=v[st];
        return 1;
    }
    ll mid=(st+en)>>1;
    ll fl=build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    if(fl==1){
        tree[node]=tree[2*node]|tree[2*node+1];
        return 0;
    }
    else{
        tree[node]=tree[2*node]^tree[2*node+1];
        return 1;
    }
}
ll update(ll node, ll st, ll en, ll ind, ll val){
    if(st==en){
        tree[node]=val;
        v[ind]=val;
        return 1;
    }
    ll mid=(st+en)>>1; 
    ll fl;
    if(ind<=mid)fl=update(2*node, st, mid, ind, val);
    else fl=update(2*node+1, mid+1, en, ind, val);
    if(fl==1){
        tree[node]=tree[2*node]|tree[2*node+1];
        return 0;
    }
    else{
        tree[node]=tree[2*node]^tree[2*node+1];
        return 1;
    }  
}
int main(){
    ll n, n_, m;
    cin>>n>>m;
    for(ll i=0; i<(1ll<<n); i++)cin>>v[i];
    n_=(1ll<<n);
    build(1, 0, n_-1);
    //cout<<tree[1]<<endl;
    while(m--){
        ll ind, val;
        cin>>ind>>val;
        ind--;
        update(1, 0, n_-1, ind, val);
        cout<<tree[1]<<endl;
    }
}