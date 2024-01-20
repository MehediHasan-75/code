#include<bits/stdc++.h>
#define ll unsigned long long
#define ll28 __int128_t
using namespace std;
bool func(ll28 a, ll28 w, ll28 h, ll28 n){
    ll28 x=a/w, y=a/h;
    return x*y >= n;
}
int main(){
    ll w, h, n;
    cin>>w>>h>>n;
    ll hi=1e18, lo=0, ans=0;
    while(hi>=lo){
        //cout<<hi<<" "<<lo<<endl;
        ll mid=(hi-lo)/2+lo;
        if(func(mid, w, h, n)){
            //cout<<mid<<endl;
            ans=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    cout<<ans<<endl;
}