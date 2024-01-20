#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
struct triplate{
    ll l, r, ind;
};
bool comp(triplate a, triplate b){
    return a.r<b.r;
}
vector<ll>tree(8*N, 0);
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
    triplate init;
    init.l=init.r=-1;
    vector<triplate>v(n, init);
    for(ll i=0; i<2*n; i++){
        ll a;
        cin>>a;
        a--;
        v[a].ind=a;
        if(v[a].l==-1)v[a].l=i;
        else v[a].r=i;
    }
    sort(v.begin(), v.end(), comp);
    // for(auto &it: v){
    //     cout<<it.l<<" "<<it.r<<" "<<it.ind<<endl;
    // }
    vector<ll>ans(n);
    for(auto &it: v){
        ll ind=it.ind, l=it.l, r=it.r;
        ans[ind]=(r-l-1)-2*query(1, 0, 2*n-1, l, r);
        update(1, 0, 2*n-1, l);
    }
    for(auto &it: ans)cout<<it<<" ";
}