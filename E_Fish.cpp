//My first NP hard porblem in codeforces

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
double eps = 1e-12;
#define precision(n) cout << setprecision(n) << fixed;
typedef long double ld;

ld proba[20][20],dp[1ll<<19];
ll n;
ld pMove(ll prev_mask, ll prev_fish){
    ll k=__builtin_popcount(prev_mask);
    ld den=(k-1)*k*1./2.0, sum=0;
    for(ll fish=0; fish<n; fish++){
        if((1<<fish)&prev_mask){// prev_fish will lose.
            sum+=proba[fish][prev_fish];
        }
    }
    return sum/den;
}
ld func(ll mask){
    ll alive= __builtin_popcount(mask);
    if(alive==n){
        return 1;
    }
    ld ans=0;
    if(dp[mask]>-0.9)return dp[mask];

    for(ll fish=0; fish<n; fish++){
        if(!(mask&(1ll<<fish))){//If fist is not alive. Let us consider the scenarion before it.
            ll prev_mask=(mask^(1<<fish));// the fish is alive 
            ld prev_day=func(prev_mask);
            ans+=prev_day*pMove(prev_mask, fish);
        }
    }
    return dp[mask]=ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cin>>proba[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    for(ll i=0; i<n; i++){
        precision(7);
        cout<<func(1ll<<i)<<" ";// let,s the only remaining fish is the ith fish.
    }
    cout<<endl;
}
