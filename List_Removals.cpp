#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
vector<ll>tree(N*4, 0), v(N);
void update(ll node, ll st, ll en, ll ind){
    if(st==en){
        tree[node]=1;
        return;
    }
    ll mid=(st+en)>>1;
    if(ind<=mid)update(2*node, st, mid, ind);
    else update(2*node+1, mid+1, en, ind);
    tree[node]= tree[2*node] + tree[2*node+1];
}
ll query(ll node, ll st, ll en, ll val){
    if(st==en){
        //cout<<st<<" ";
        //cout<<tree[node]<<endl;
        tree[node]=0;
        return v[st];
    }
    ll mid=(st+en)>>1;
    ll ans;
    if(tree[node*2]>=val){
        ans=query(2*node, st, mid, val);
    }
    else {
        ans=query(2*node+1, mid+1, en, val-tree[2*node]);
    }
    tree[node]=(tree[2*node]+ tree[2*node+1]);
    return ans;
}
int main(){
    ll n;
    cin>>n;
    // cout<<n<<endl;
    for(ll i=0; i<n; i++){
        cin>>v[i];
        update(1, 0, n-1, i);
    }
    ll n_=n;
    while(n_--){
        ll a;
        cin>>a;
        // cout<<a<<" ";
        ll x=query(1, 0, n-1, a);
        cout<<x<<" ";
    }
}