#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
vector<ll>tree(N*4);
void update(ll node, ll st, ll en, ll ind, ll val){
    if(st==en){
        if(ind%2)tree[node]=-val;
        else tree[node]=val;
        return;
    }
    ll mid=(st+en)>>1;
    if(ind<=mid)update(2*node, st, mid, ind, val);
    else update(2*node+1, mid+1, en, ind, val);
    tree[node]=tree[2*node]+tree[2*node+1];
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
    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        update(1, 0, n-1, i, a);
    }
    //cout<<tree[1];
    ll q;
    cin>>q;
    while(q--){
        ll type;
        cin>>type;
        if(type){
            ll l, r;
            cin>>l>>r;
            //cout<<l<<" "<<r<<endl;
            l--, r--;
            ll ans=query(1, 0, n-1, l, r);
            if(l%2==1)ans=-ans;
            cout<<ans<<endl;
        }
        else{
            ll ind, val;
            cin>>ind>>val;
            ind--;
            update(1, 0, n-1, ind, val);
        }
    }
}