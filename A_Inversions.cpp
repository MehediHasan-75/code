#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
vector<ll>v(N), tree(N*4, 0);
void combine(ll node, ll l, ll r){
    tree[node]=tree[l]+tree[r];
}
void update(ll node, ll st, ll en, ll ind){
    if(st==en){
        tree[node]+=1;
        return;
    }
    ll mid=(st+en)>>1;
    if(ind<=mid){
        update(2*node, st, mid, ind);
    }
    else{
        update(2*node+1, mid+1, en, ind);
    }
    combine(node, 2*node, 2*node+1);
}
ll query(ll node, ll st, ll en, ll l, ll r){
    if(l>en or st>r)return 0;
    if(l<=st and en<=r)return tree[node];
    else{
        ll mid=(st+en)>>1;
        return query(node*2, st, mid, l, r)+query(node*2+1, mid+1, en, l, r);
    }
}
int main(){
    ll n;
    cin>>n;
    for(ll i=0; i<n; i++)cin>>v[i];
    //cout<<"_";
    for(ll i=0; i<n; i++){
         update(1, 0, n, v[i]);
        cout<<query(1, 0, n, v[i]+1, n)<<" ";
    }
}