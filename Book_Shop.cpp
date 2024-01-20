#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1001]
ll func(vector<ll>&price, vector<ll>&page, ll ind, ll rem){
    if(ind==page.size() or rem<=0)return 0;
 
    ll taken=0, ntaken=0;
    if(dp[ind]!=-1)return dp[ind];
    if(rem>=price[ind]){
        taken=page[ind]+func(price, page, ind+1, rem-price[ind]);
    }
    ntaken=func(price, page, ind+1, rem);
    return dp[ind]=max(taken, ntaken);
}
int main(){
    ios_base::sync_with_stdio(false);
    ll n, tk;
    cin>>n>>tk;
    memset(dp, -1, sizeof(dp));
    vector<ll>price(n),page(n);
    
    for(auto &it:price)cin>>it;
    for(auto &it:page)cin>>it;
    cout<<func(price,page,0, tk);
}