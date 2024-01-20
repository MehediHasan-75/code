#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll pi_func(string s, ll m){
    ll n=s.length(), cnt=0;
    vector<ll>pi(n, 0);
    for(ll i=1; i<n; i++){
        ll j=pi[i-1];
        while(j>0 and s[i]!=s[j])j=pi[j-1];
        if(s[i]==s[j])j++;
        if(j==m)cnt++, j=0;
        pi[i]=j;
    }
    return cnt;
}
int main(){
    while(1){
        string s1, s2;
        cin>>s1;
        if(s1=="#")return 0;
        cin>>s2;
        string s=s2+" "+s1;
        ll ans=pi_func(s, s2.length());
        cout<<ans<<endl;
    }
}