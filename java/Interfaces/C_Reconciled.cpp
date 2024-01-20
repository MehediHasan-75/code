#include<bits/stdc++.h>
#define ll long long
#define  mod 1000000007
using namespace std;
int main(){
    ll dog, monkey;
    cin>>dog>>monkey;
    if(abs(dog-monkey)>1)cout<<0<<endl;
    else{
        if(dog>monkey)swap(dog, monkey);
        ll ans1=1, ans=1;
        for(ll i=1; i<=dog; i++)ans*=i, ans%=mod;
        for(ll i=1; i<=monkey; i++)ans1*=i, ans1%=mod;
        ans1*=(monkey+1), ans1%=mod;
        cout<<(ans1+ans)%mod<<endl;     
    }
}