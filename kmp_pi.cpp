
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
vector<ll>prefix_function(string s){
    ll n=s.length();
    vector<ll>pi(n,0);
    for(ll i=1; i<n; i++){
        ll j=pi[i-1];
        while(j>0 and s[i]!=s[j]) j=pi[j-1];
        if(s[j]==s[i])j++;
        pi[i]=j;
    }
    return pi;
}
void solve(ll tc)
{
    string s;
    cin>>s;
    // cout<<s<<endl;
    vector<ll>pi=prefix_function(s);
    prnt(pi);
}
int main()
{
    fastio;ll T = 1;
    //cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}