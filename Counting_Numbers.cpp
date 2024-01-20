#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[20][11][3];

ll func(ll ind, string num, ll prev, ll tight){
    if(ind==num.size()){
        return 1;
    }
    if(prev!=-1 and dp[ind][prev][tight]!=-1)return dp[ind][prev][tight];
    ll range=9;
    if(tight)range=num[ind]-'0';

    ll ans=0;
    for(ll i=0; i<=range; i++){
        if(i==prev)continue;
        ll newpre=i;
        if(i==0 and prev==-1)newpre=-1;
        ans+=func(ind+1, num, newpre, tight&(i==(num[ind]-'0')));
    }
    return dp[ind][prev][tight]=ans;
}
int main(){

    ll a, b;

    cin>>a>>b;
    a--;
    string num1=to_string(a), num2=to_string(b);

    memset(dp, -1, sizeof(dp));
    ll ans2=func(0, num2,-1, 1);

    memset(dp, -1, sizeof(dp));
    ll ans1=func(0, num1, -1, 1);

    cout<<ans2-ans1<<endl;
}