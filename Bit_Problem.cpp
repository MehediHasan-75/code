#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll Log=20, mxN=1<<Log;
vector<ll>ans1(mxN, 0), ans2(mxN, 0), ans3(mxN, 0);
int main(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(auto &it: v)cin>>it, ans1[it]++, ans2[it]++, ans3[it]++;
    for(ll i=0; i<Log; i++){
        for(ll j=0; j<mxN; j++){
            if((j&(1<<i))){
                ans1[j]+=ans1[j^(1<<i)];
            }
        }
    }
    for(ll i=0; i<Log; i++){
        for(ll j=0; j<mxN; j++){
            if((j&(1<<i))==0){
                ans2[j]+=ans2[j^(1<<i)];
            }
        }
    }
    for(auto &it: v)cout<<ans1[it]<<" "<<ans2[it]<<" "<<n-ans1[((mxN-1)^it)]<<endl;

}