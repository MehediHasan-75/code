#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
vector<ll>tree(N*4, 0);
void update(ll node, ll st, ll en, ll ind, ll val){
    if(st==en){
        tree[node]=val;
        return;
    }
    ll mid=(st+en)>>1;
    if(ind<=mid)update(2*node, st, mid, ind, val);
    else update(2*node+1, mid+1, en, ind, val);
    tree[node]=max(tree[2*node], tree[2*node+1]);
}
ll query(ll node, ll st, ll en, ll val){
    if(st==en){
        tree[node]-=val;
        return st;
    }
    ll mid=(st+en)>>1;
    ll ans;
    if(tree[2*node]>=val){
        ans=query(2*node, st, mid, val);
    }
    else {
        ans=query(2*node+1, mid+1, en, val);
    }
    tree[node]=max(tree[2*node], tree[2*node+1]);
    return ans;
}
int main(){
    ll n, q;
    cin>>n>>q;
    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        update(1, 0, n-1, i, a);
    }
    while(q--){
        ll a;
        cin>>a;
        if(a>tree[1])cout<<0<<" ";
        else cout<<query(1, 0, n-1, a)+1<<" ";
    }
}