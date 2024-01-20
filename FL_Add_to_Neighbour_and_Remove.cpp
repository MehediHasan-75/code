//Total sum can only distributed in some segement such that sum of each segment is always a divisor of total sum.
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll func(vector<ll>&v, ll sm){
    ll j=0, n=v.size(), op=0, sum=0;
    for(ll i=0; i<n; i++){
        sum+=v[i];
        if(sum==sm){
            op+=i-j;
            j=i+1;
            sum=0;
        }
        else if(sum>sm)return INT64_MAX;
    }
    return op;
}
void solve(){
    ll n;
    cin>>n;

    vector<ll>v(n);
    ll sum=0, ans=INT64_MAX;
    for(auto &it: v)cin>>it, sum+=it;

    for(ll i=1; i*i<=sum; i++){
        if(sum%i==0){
            ll s1=i, s2=sum/i;
            ans=min(func(v, s1), ans);
            ans=min(func(v, s2), ans);
        }
    }
    cout<<ans<<endl;
}
int main(){
    ll t;
    cin>>t;

    while(t--)solve();
}