#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
vector<ll>pi_func(string s){
    ll n=s.length();
    vector<ll>pi(n, 0);
    for(ll i=1; i<n; i++){
        ll j=pi[i-1];
        while(j>0 and s[i]!=s[j])j=pi[j-1];
        if(s[i]==s[j])j++;
        pi[i]=j;
    }
    return pi;
}
int main(){
    fastio;
    while(1){
        string s;
        cin>>s;
        if(s==".")break;
        vector<ll>pi=pi_func(s);
        //prnt(pi);
        ll n=s.size(), patt_len=n-pi[n-1];
        // cout<<(n%(n-pi[n-1])<<endl;
        // cout<<n<<endl;
        //cout<<patt_len<<" "<<n<<endl;
        if(patt_len && (n%patt_len==0))cout<<(n/patt_len)<<"\n";
        else cout<<1<<"\n";
    }
}