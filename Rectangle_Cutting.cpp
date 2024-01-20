#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>>dp(501, vector<ll>(501, 0));
ll func(ll a, ll b){

    if(a==b)return 0;
    ll ans=INT64_MAX;
    if(dp[a][b]!=-1)return dp[a][b];
    for(ll i=1; i<a; i++){
        ans=min(ans, 1+func(i, b)+func(a-i, b));
    }
    for(ll i=1; i<b; i++){
        ans=min(ans, 1+func(a, i)+func(a, b-i));
    }
    return dp[a][b]=ans;

}
int main(){
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin>>n>>m;
    for(ll a=1; a<=n; a++){
        for(ll b=1; b<=m; b++){
            if(a==b){
                dp[a][b]=0;
                continue;
            }
            ll ans=INT64_MAX;
            for(ll i=1; i<a; i++){
                ans=min(ans, 1+dp[i][b]+dp[a-i][b]);
            }
            for(ll i=1; i<b; i++){
                ans=min(ans, 1+dp[a][i]+ dp[a][b-i]);
            }
            dp[a][b]=ans;
        }
    }
    cout<<dp[n][m];
}