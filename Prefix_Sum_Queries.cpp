#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
struct nd{
    ll sum, pre, suff, ans;
};
vector<nd>tree(N*4);
nd combine(nd l, nd r){
    nd res;
    res.sum=l.sum+r.sum;
    res.pre=max(l.sum+r.pre, l.pre);
    res.suff=max(r.sum+l.suff, r.suff);
    res.ans=max(max(l.ans, r.ans), l.suff+r.pre);
    return res;
}
void update(ll node, ll st, ll en, ll ind, ll val){
    if(st==en){
        tree[node]={val,max(0ll,val), max(0ll,val), max(0ll,val)};
        return ;
    }
    ll mid=(st+en)>>1;
    if(ind<=mid)update(2*node, st, mid, ind, val);
    else update(2*node+1, mid+1, en, ind, val);
    tree[node]=combine(tree[2*node], tree[2*node+1]);
}
int main(){
    ll n, q;
    cin>>n>>q;
    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        update(1, 0, n-1, i, a);
    }
    cout<<tree[1].ans<<endl;
}