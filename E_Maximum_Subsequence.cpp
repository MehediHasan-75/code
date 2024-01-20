#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>v;
set<ll>allSubsetSum(vector<ll>&v, ll m){

    set<ll>st;
    for(ll mask=0; mask<(1<<v.size()); mask++){
        ll sm=0;
        for(ll i=0; i<v.size(); i++){
            if(mask&(1<<i)){
                sm+=v[i];
                sm%=m;
            }
        }
        st.insert(sm);
    }
    return st;
}

int main(){
    ll n, m;
    cin>>n>>m;

    vector<ll>v(n);
    for(auto &it: v)cin>>it;

    auto mi = next(v.begin(), v.size() / 2);
    vector<ll> l(v.begin(), mi), r(mi, v.end());

    set<ll>stl=allSubsetSum(l, m), str=allSubsetSum(r, m);

    ll mx=0;
    for(auto &it: stl){
        auto it1=str.upper_bound((m-it-1));
        it1--;
        mx=max(mx, it+ *it1);
    }
    cout <<mx<<"\n";
}