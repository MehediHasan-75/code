#include<bits/stdc++.h>
using namespace std;
int main(){
    typedef long long ll;
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll cnt=0;
    for(ll i=0; i<n; i++){
        cnt++;
        cout<<s[i];
        for(ll j=0; j<cnt; j++)i++;
    }
}