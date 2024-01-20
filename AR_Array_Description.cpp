#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>v(2001);
ll n, m;
ll dp[2001][2001];
ll func(){
    
}
int main(){
    memset(dp, -1, sizeof(dp));
    cin>>n>>m;
    for(ll i=0; i<n; i++)cin>>v[i];
    cout<<max(v[0]+func(2, 1),func(1, 1));
}