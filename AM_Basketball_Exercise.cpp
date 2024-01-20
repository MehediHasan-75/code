#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
vector<ll>v1(N), v2(N);
ll n;
ll dp[N][3];
ll func(ll ind, ll prev){
    //cout<<prev<<" ";
    if(ind>=n)return 0;
    if(dp[ind][prev]!=-1)return dp[ind][prev];
    ll mx=0;
    if(prev==0){
            mx=max(v2[ind]+func(ind+2, 2), v2[ind]+func(ind+1, 2));
            mx=max(mx,max(v1[ind]+func(ind+2, 1), v1[ind]+func(ind+1, 1)));       
    }
    else if(prev==1){
            mx=max(v2[ind]+func(ind+2, 2), v2[ind]+func(ind+1, 2));
    }
    else{
            mx=max(v1[ind]+func(ind+2, 1), v1[ind]+func(ind+1, 1));
    }
    return dp[ind][prev]=mx;
} 
int main(){
    fastio;
    memset(dp, -1, sizeof(dp));
    cin>>n;
    for(ll i=0; i<n; i++)cin>>v1[i];
    for(ll i=0; i<n; i++)cin>>v2[i];
    cout<<func(0,0)<<endl;
}