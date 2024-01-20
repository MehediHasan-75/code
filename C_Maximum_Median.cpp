#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5 +10;
ll n, k;
vector<ll>v(N);
bool chk(ll mid){
    ll sm=0;
    for(ll i=n-1; i>=n/2; i--){
        sm+=max(0ll, mid-v[i]);
    }
    return sm<=k;
}
int main(){
    cin>>n>>k;
    for(ll i=0; i<n ; i++)cin>>v[i];
    sort(v.begin(), v.begin()+n);
    //for(ll i=0; i<n; i++)cout<<v[i]<<" ";
    ll ans=v[n/2], lo=ans, hi=1e14+10;
    while(hi>=lo){
        ll mid=(hi-lo)/2 +lo;
        if(chk(mid)){
            ans=mid;
            lo=mid+1;
        }
        else hi=mid-1;
    }
    cout<<ans<<endl;
}