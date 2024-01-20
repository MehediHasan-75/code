#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>v(1005);
ll n, k;
bool check(ll need){
    ll sm=0, x=need, fl=0;
    for(ll i=0; i<n-1; i++){
        if(v[i]>=need)return true;
        x=need, fl=0, sm=0;
        sm+=x-v[i];
        for(ll j=i+1; j<n; j++){
            x--;
            if(v[j]>=x){
                fl=1;
                break;
            }
            sm+=x-v[j];
        }
        if(sm<=k and fl)return true;
    }
    return false;
}
void solve(){
    ll mx=0;
    cin>>n>>k;
    for(ll i=0; i<n; i++){
        cin>>v[i];
        mx=max(mx, v[i]);
    }
    ll hi=1e14, lo=0, ans=0;
    while(hi>=lo){
        ll mid=(hi+lo)/2;
        if(check(mid)){
            ans=mid;
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    cout<<max(ans, mx)<<endl;
}
int main(){
    ll t;
    cin>>t;
    while(t--)solve();
}