#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    string s;
    cin>>s;
    map<ll,ll>mp;
    ll x=0, cnt=0;
    mp[x]++;
    for(ll i=0; i<s.size(); i++){
        ll dig=s[i]-'0';
        x^=(1ll<<dig);
        cnt+=mp[x];
        mp[x]++;
    }
    cout<<cnt<<endl;
}