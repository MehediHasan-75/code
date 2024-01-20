#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;

ll dp[2005][2005];
ll func(ll n, ll k, ll num){
    if(k==0)return 1;
    if(dp[k][num]!=-1)return dp[k][num];
    ll ans=0;
    for(ll i=num; i<=n; i+=num){
        ans=(ans+func(n, k-1, i))%mod;
    }
    return dp[k][num]=ans;
}
int main(){
    ll n, k;
    cin>>n>>k;
    memset(dp, -1, sizeof(dp));
    ll ans=0;
    for(ll i=1; i<=n; i++)ans=(ans+func(n, k-1, i))%mod;
    cout<<ans<<endl;
}