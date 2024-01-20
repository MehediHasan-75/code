#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n, q;
    cin>>n>>q;

    vector<ll>v(n+1, INT64_MIN);
    vector<ll>ans;
    ll cnt=0;
    for(ll i=0; i<q; i++){
        ll x, y, dif;
        cin>>x>>y>>dif;


        if(v[x]==INT64_MIN and v[y]==INT64_MIN){
            v[x]=0;
            v[y]=dif;
            ans.push_back(i);
        }
        else if(v[x]==INT64_MAX){
            v[x]=v[y]-dif;
            ans.push_back(i);
        }
        else if(v[y]==INT64_MIN){
            v[y]=v[x]+dif;
            ans.push_back(i);
        }
        else{
            if(v[y]-v[x]==dif)ans.push_back(i);
        }
    }
    for(auto &it: ans)cout<<it<<" ";
    cout<<endl;
}