#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>hash_func(string s,ll base, ll mod){
    ll n=s.size();
    vector<ll>power(n), hash(n+1,0);
    power[0]=1;
    for(ll i=1; i<n; i++){
        power[i]=(power[i-1]*base)%mod;
    }
    for(ll i=0; i<n; i++){
        hash[i+1]=(hash[i]+power[i]*(s[i]-'a'+1))%mod;
    }
    return hash;
}
ll hash_value(string s, ll base, ll mod){
    ll val=0;
    ll n=s.size();
    for(ll i=0; i<n; i++){
        val=(val*base+s[i]-'a'+1)%mod;
    }
    return val;
}
int main(){
    ll base, mod;
    string s;
    cin>>base>>mod;
    //cout<<base<<" "<<mod<<endl;
    cin>>s;
    vector<ll>v=hash_func(s,base, mod);
    for(ll i=1; i<=s.size(); i++)cout<<v[i]<<" ";
    cout<<endl;
    cout<<hash_value(s, base, mod)<<endl;
}