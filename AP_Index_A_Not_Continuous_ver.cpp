#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>v(2001);
ll n, m;
ll dp[2001][2001];
ll func(ll cnt_m, ll ind){

    if(cnt_m==m+1)return 0;
    if(ind==n)return -1e+14;
    if(dp[cnt_m][ind]!=-1)return dp[cnt_m][ind];
    ll mx=max( v[ind]*cnt_m+func(cnt_m+1, ind+1), func(cnt_m, ind+1));

    return dp[cnt_m][ind]=mx;
}
int main(){
    memset(dp, -1, sizeof(dp));
    cin>>n>>m;
    for(ll i=0; i<n; i++)cin>>v[i];
    cout<<max(v[0]+func(2, 1),func(1, 1));
}