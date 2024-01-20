#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>v(500);
ll n, k;

ll chk(ll x){
    vector<ll>temp;
    for(ll i=0; i<n; i++){
        if(v[i]%x)temp.push_back(v[i]%x);
    }
    sort(temp.begin(), temp.end());

    ll lo=0, hi=temp.size()-1, oper=0, sm=0;
    while(lo<=hi){
        if(sm<=0){
            sm+=temp[lo];
            oper+=temp[lo];
            lo++;
        }
        else{
            sm-=(x-temp[hi]);
            oper+=(x-temp[hi]);
            hi--;
        }
    }
    if(sm!=0 or 2*k<oper)return 0;
    return 1;
}
int main(){
    cin>>n>>k;
    ll sm=0;
    for(ll i=0; i<n; i++){
        cin>>v[i];
        sm+=v[i];
    }
    ll mx=1;
    for(ll i=1; i*i<=sm; i++){
        if(sm%i==0){
            if(chk(i))mx=max(mx, i);
            if(chk(sm/i))mx=max(mx, sm/i);
        }
    }
    cout<<mx<<endl;
}
