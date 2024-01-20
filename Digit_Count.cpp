#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
vector<ll>v(12);
map<ll,ll>mp;
ll solve(ll ind, ll prev, ll num){
    // cout<<prev<<endl;
    if(ind==n){
        // cout<<num<<endl;
        return 1;
    }
    ll cnt=0;
    for(ll i=0; i<m; i++){
        // cout<<prev<<" "<<v[i]<<endl;
        // cout<<abs(prev-v[i])<<endl;
        if(abs(prev-v[i])<=2)cnt+=solve(ind+1, v[i], num*10+v[i]);
    }
    return cnt;
}
void sol(ll tc){
    cout<<"Case "<<tc<<": ";
    cin>>m>>n;
    for(ll i=0; i<m; i++)cin>>v[i];
    // for(auto &it: v)cout<<it<<endl;
    ll cnt=0;
    for(ll i=0; i<m; i++){
        cnt+=solve(1, v[i], v[i]);
    }
    cout<<cnt;
    cout<<"\n";
    mp.clear();
}
int main(){
    ll t;
    cin>>t;
    // cout<<t<<endl;
    for(ll i=1;i <=t; i++)sol(i);
}