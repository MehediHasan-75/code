#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
vector<ll>v(N), tree(4*N);
//build(1, 0, n-1);
//query(1, 0, n-1, l, r);
ll h,ind;
ll query(ll node, ll st, ll en, ll ind, ll tr, ll ty){
    if(st==en)return 0;
    ll mid=(st+en)>>1ll;
    ll ht=h-tr;
    //cout<<mid<<"  "<<st<<" "<<en<<" "<<ty<<endl;
   // cout<<tr<<" "<<h-tr<<endl;

    if(ind<=mid){
        ll val=1;
        //cout<<"hi1 ";
        if(ty==1)val+=(1ll<<(ht+1))-1;
        //cout<<val<<endl;
        return val+query(2*node, st, mid, ind, tr+1, 1);
    }
    else{
        ll val=1;
        //cout<<"hi2 ";
        if(ty==0)val+=(1ll<<(ht+1))-1;
        //cout<<val<<endl;
        return val+query(2*node+1, mid+1, en, ind, tr+1, 0);
    }
}
int main(){
    cin>>h>>ind;
    ll n=(1ll<<h);
    ind--;
    cout<<query(1, 0, n-1, ind, 1, 0);
}