
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 2e5 + 10, inf=2e18;
ll mod = 1000000007;
map<ll,ll>mp;
vector<ll> pi_func(string s){
    ll n=s.size();
    vector<ll>pi(n,0);
    for(ll i=1; i<n; i++){
        ll j=pi[i-1];
        while(j>0 and s[i]!=s[j])j=pi[j-1];
        if(s[i]==s[j])j++;
        pi[i]=j;
        mp[j]++;
    }
    return pi;
}
void solve(ll tc)
{
    string s;
    cin>>s;
    vector<ll>last=pi_func(s);
    // for(auto &it: last)cout<<it<<" ";
    // cout<<endl;
    ll rem=s.size()-last.back();
    if((last.back()!=0 and mp[last.back()]>1)){
        for(ll i=0; i<last.back(); i++)cout<<s[i];
        cout<<endl;
    }
    else if(last.back()!=0 and last[last.back()-1]!=0){
        for(ll i=0; i<last[last.back()-1]; i++)cout<<s[i];
        cout<<endl;
    }
    else cout<<"Just a legend\n";
}
int main()
{
    fastio;ll T = 1;
    //cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

