#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
  return (a / gcd(a, b)) * b;
}
int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll>v(k);
    for(ll i=0; i<k; i++)cin>>v[i];
    ll cnt=0;
    for(ll i=0; i<(1ll<<k); i++){
        ll ct=0, lc=1, x=0;
        for(ll j=0; j<k; j++){
            if((i&(1ll<<j))){
                ct++;
                lc=lcm(lc, v[j]);
            }
        }
        if(ct!=0)x=n/lc;
        if(ct%2)cnt+=x;
        else cnt-=x;
    }
    cout<<n-cnt<<endl;
}