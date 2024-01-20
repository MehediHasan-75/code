#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct nod{
    ll cnt, mi;
};
const int N= 1e5 +5;
vector<ll>v(N);
vector<nod>tree(N*4);
void build(ll node, ll st, ll en){
    if(st==en){
        tree[node]={1, v[st]};
        return;
    }
    ll mid=(st+en)>>1;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    ll left=2*node, right=2*node+1;

    if(tree[left].mi < tree[right].mi){
        tree[node]=tree[left];
    }
    else if(tree[left].mi > tree[right].mi){
        tree[node]=tree[right];
    }
    else{
        tree[node]=tree[left];
        tree[node].cnt += tree[right].cnt;
    }
    return;
}
nod query(ll node, ll st, ll en, ll l, ll r){
    if(r<st or l>en){
        return {0, INT64_MAX};
    }
    if(l<=st and en<=r)return tree[node];
    ll mid=(st+en)>>1;
    nod left=query(2*node, st, mid, l, r);
    nod right=query(2*node+1, mid+1, en, l, r);

    if(left.mi < right.mi){
        return left;
    }
    else if(left.mi > right.mi){
        return right;
    }
    else{
        nod nd;
        nd=left;
        nd.cnt +=right.cnt;
        return nd;
    }
}
void update(ll node, ll st, ll en, ll ind, ll val){
    if(st==en){
        tree[node]={1, val};
        v[ind]=val;
        return;
    }
    ll mid=(st+en)>>1;
    if(ind<=mid){
        update(2*node, st, mid, ind, val);
    }
    else update(2*node+1, mid+1, en, ind, val);
    ll left=2*node, right=2*node+1;

    if(tree[left].mi < tree[right].mi){
        tree[node]=tree[left];
    }
    else if(tree[left].mi > tree[right].mi){
        tree[node]=tree[right];
    }
    else{
        tree[node]=tree[left];
        tree[node].cnt += tree[right].cnt;
    }
    return;
}
int main(){
    ll n, m;
    cin>>n>>m;
    for(ll i=0; i<n; i++)cin>>v[i];
    // for(ll i=0; i<n; i++)cout<<v[i]<<" ";
    build(1, 0, n-1);
    //for(ll i=0; i<10; i++)cout<<tree[i].mi<<" "<<tree[i].cnt<<endl;
    while(m--){
        ll q;
        cin>>q;
        if(q==1){
            ll ind, val;
            cin>>ind>>val;
            update(1, 0, n-1, ind, val);
            //for(ll i=0; i<n; i++)cout<<v[i]<<" ";
            //cout<<endl;
        }
        else{
            ll l, r;
            cin>>l>>r;
            auto it=query(1, 0, n-1, l, r-1);
            cout<<it.mi<<" "<<it.cnt<<endl;
        }
    }
}