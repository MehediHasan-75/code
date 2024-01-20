#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
struct nd{
    ll sum, mx;
};
vector<nd>tree(N*4);
void combine(ll node, ll l, ll r){
    tree[node].sum=tree[l].sum+tree[r].sum;
    tree[node].mx=max(tree[l].mx, tree[r].mx);
}
void update(ll node, ll st, ll en, ll ind, ll val){
    if(st==en){
        tree[node].sum=tree[node].mx=val;
        return;
    }
    ll mid=(st+en)>>1;
    if(ind<=mid)update(node*2, st, mid, ind, val);
    else update(node*2+1, mid+1, en, ind, val);
    combine(node, 2*node, 2*node+1);
}

void mod(int node,int st,int en,int l,int r,int x)
{
	if(tree[node].mx<x) return;
	if(st>r||en<l) return ;
	if(st==en)
	{
		tree[node].sum=tree[node].mx=tree[node].sum%x;
		return ;
	}
	int mid=(st+en)/2;
	mod(2*node,st,mid,l,r,x);
	mod(2*node+1,mid+1,en,l,r,x);
	combine(node, node*2, node*2+1);
}
ll query(ll node, ll st, ll en, ll l, ll r){
    if(l>en or st>r)return 0;
    if(l<=st and en<=r)return tree[node].sum;
    else{
        ll mid=(st+en)>>1;
        return query(node*2, st, mid, l, r)+query(node*2+1, mid+1, en, l, r);
    }
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
        ll type;
        cin>>type;
        if(type==1){
            ll l, r;
            cin>>l>>r;
            l--, r--;
            cout<<query(1, 0, n-1, l, r)<<endl;
        }
        else if(type==2){
            ll l, r, x;
            cin>>l>>r>>x;
            l--, r--;
            mod(1, 0, n-1, l, r, x);
        }
        else{
            ll ind, val;
            cin>>ind>>val;
            ind--;
            update(1, 0, n-1, ind, val);
        }
    }
}