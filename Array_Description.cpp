#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[100005];
ll func(vector<ll>&v, ll ind, ll m){

    if(ind==v.size()){
        for(ll i=1; i<v.size(); i++){
            if(abs(v[i]-v[i-1])>1)return 0;
        }
        return 1;
    }

    ll ans=0;
    if(v[ind]==0){
            for(ll i=1; i<=m; i++){
                v[ind]=i;
                ans+=func(v, ind+1, m);
                v[ind]=0;
            }
    }
    else{
        ans+=func(v, ind+1, m);
    }
    return ans;
}

int main(){
    ll n, m;
    cin>>n>>m;
    memset(dp, -1, sizeof(dp));
    vector<ll>v(n);
    for(auto &it: v)cin>>it;

    cout<<func(v, 0, m);
    // cout<<cnt<<endl;
}