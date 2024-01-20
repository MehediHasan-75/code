#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
vector<ll>v(N), tree(4*N);
//build(1, 0, n-1);
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
//similar to binary search.update(1, 0, n-1, ind, val);
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
int main(){
    ll n, q;
    cin>>n>>q;
    for(ll i=0; i<n; i++)cin>>v[i];
    build(1, 0, n-1);
    while(q--){
        ll type;
        cin>>type;
        if(type==2){
            ll l, r;
            cin>>l>>r;
            l--, r--;
            cout<<query(1, 0, n-1, l, r)<<endl;
        }
        else{
            ll ind, val;
            cin>>ind>>val;
            ind--;
            update(1, 0, n-1, ind, val);
        } 
    }
}