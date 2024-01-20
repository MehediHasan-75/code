#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;

ll n, dp[N][2];
string s;
ll func(ll ind, ll val){
    if(ind>=n){
        return 0;
    }
    if(dp[ind][val]!=-1) return dp[ind][val];
    if(s[ind]-'0'==val) return dp[ind][val]=0;
    return dp[ind][val]=1+func(ind+1, !val);
}
void solve(){
    memset(dp, -1, sizeof(dp));
    cin>>s;
    n=s.size();

    ll ans=0;
    for(ll i=0; i<n; i++){
        if(s[i]=='?')ans+=1+max(func(i+1, 0),func(i+1, 1));
        else ans+=1+func(i+1, s[i]-'0');
    }
    cout<<ans<<endl;
}
int main(){
    ll t;
    cin>>t;
    while(t--)solve();
}