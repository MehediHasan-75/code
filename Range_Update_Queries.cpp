#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
vector<ll>tree(N*4,0), v(N);
void build(ll node, ll st, ll en){
    if(st==en){
        tree[node]=v[st];
        return;
    }
    ll mid=(st+en)>>1;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
}
void update(ll node, ll st, ll en, ll l, ll r, ll val){
    if(en<l or r<st)return;
    if(st>=l and en<=r){
        tree[node]+=val;
        return;
    }
    ll mid=(st+en)>>1;
    update(2*node, st, mid, l , r, val);
    update(2*node+1, mid+1, en, l , r, val);
}
/**/
ll query(ll node, ll st, ll en, ll ind){
    if(st==en)return tree[node];
    ll mid=(st+en)>>1;
    if(ind<=mid){
        return tree[node]+query(2*node, st, mid, ind);
    }
    else{
        return tree[node]+query(2*node+1, mid+1, en, ind);
    }
}
/*int get(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(v*2, tl, tm, pos);
    else
        return t[v] + get(v*2+1, tm+1, tr, pos);
}*/
int main(){
    ll n, m;
    cin>>n>>m;
    for(ll i=0; i<n; i++)cin>>v[i];
    build(1, 0, n-1);
    while(m--){
        ll type;
        cin>>type;
        if(type==1){
            ll l, r, val;
            cin>>l>>r>>val;
            l--, r--;
            update(1, 0, n-1, l, r, val);
        }
        else {
            ll ind;
            cin>>ind;
            ind--;
            cout<<query(1, 0, n-1, ind)<<endl;
        }
    }
}