#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7, N= 62625+10;

ll dp[N][505];

ll func(ll sum, ll num, ll n){
    if(sum<0 or num>n)return 0;
    if(sum==0)return 1;
    if(dp[sum][num]!=-1)return dp[sum][num];
    ll ans=((func(sum-num, num+1, n)%mod)+ (func(sum, num+1, n)%mod))%mod;
    return dp[sum][num]=ans;
}
int main(){
    ll n;
    cin>>n;
    memset(dp, -1, sizeof(dp));

    ll sum=(n*(n+1))/2;
    if(sum%2){
        cout<<0;
    }
    else{
        cout<<func(sum/2, 1, n);
    }
}