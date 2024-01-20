#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    ll n, cnt=0;
    cin>>n;
    while(n){
        cnt++;
        ll n_=n, mx=0;
        while(n_){
            ll r=n_%10;
            n_/=10;
            mx=max(mx, r);
        }
        n-=mx;
    }
    cout<<cnt<<endl;
}