#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007
ll pwr(ll base, ll power){
    if(power==0)return 1ll;
    ll num=pwr(base, power/2)%mod;
    if(power%2)return(((num*num)%mod)*base)%mod;
    return (num*num)%mod;
}
int countGoodNumbers(long long n) {
    ll x=(n+1)/2, y=n-x;
    return (pwr(5,x)*pwr(4,y))%mod;     
}
int main(){
    ll n;
    cin>>n;
    cout<<countGoodNumbers(n)<<endl;
}