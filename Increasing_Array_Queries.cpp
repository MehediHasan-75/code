#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
struct nd{
    ll l, r, tot, eq, ans;
};
vector<ll>v(N);
vector<nd>tree(N*4);
nd build(nd l, nd r){
    nd res;
    if(l.r>r.l){
        res.ans+=r.eq;
        res.eq=0;
    }
}
void build(ll node, ll st, ll en){
    if(st==en){
        tree[node]={v[st], v[st], 1, 0, 0};
    }
    ll mid=(st+en)>>1;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    tree[node]=build(tree[2*node], tree[2*node+1]);
}
int main(){
    ll n, q;
    cin>>n>>q;
    for(ll i=0; i<n; i++)cin>>v[i];
    build(1, 0, n-1);
}