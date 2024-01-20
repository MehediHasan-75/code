#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k;
const int N=2e5+10;
vector<ll>v(N);
bool chk(ll R){
    ll cnt=0;
    for(ll i=0; i<n; ){
        ll val=v[i]+2*R;
        cnt++;
        while(i<n and val>=v[i]) i++;
    }
    return cnt<=k;
}
int main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    cin>>n>>k;
    for(ll i=0; i<n; i++)cin>>v[i];
    sort(v.begin(), v.begin()+n);
    // for(ll i=1; i<11; i++)cout<<chk(i)<<" "<<i<<endl;
    ll ans=0, hi=1e14+10, lo=1;
    while(hi>=lo){
        ll mid=(hi-lo)/2+lo;
        if(chk(mid)){
            ans=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    cout<<ans<<endl;
}