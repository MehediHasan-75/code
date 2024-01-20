#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>v;
multiset<ll>allSubsetSum(vector<ll>&v){

    multiset<ll>st;
    for(ll mask=0; mask<(1<<v.size()); mask++){
        ll sm=0;
        for(ll i=0; i<v.size(); i++){
            if(mask&(1<<i)){
                sm+=v[i];
            }
        }
        st.insert(sm);
    }
    return st;
}

int main(){
    ll w, mass;
    cin>>w>>mass;

    v.push_back(1);
    ll num=1, sum=0, sum1=0;
    while(num*w<=1000000000){
        v.push_back(num*w);
        num*=w;
    }
    auto mi = next(v.begin(), v.size() / 2);
    vector<ll> l(v.begin(), mi), r(mi, v.end());

    multiset<ll>stl=allSubsetSum(l), str=allSubsetSum(r);

    for(auto &it: stl){
        //left e ache m weight.
        if(stl.count(mass+it) or str.count(mass+it)){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "\n";
}