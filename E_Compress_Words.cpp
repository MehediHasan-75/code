
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
ll pi_func(string s){
    ll n=s.length();
    vector<ll>pi(n, 0);
    for(ll i=1; i<n; i++){
        ll j=pi[i-1];
        while(j>0 and s[i]!=s[j])j=pi[j-1];
        if(s[i]==s[j])j++;
        pi[i]=j;
    }
    return pi.back();
}
void solve(ll tc)
{
    ll n;
    cin>>n;
    string s[n], ans;
    for(ll i=0; i<n; i++)cin>>s[i];
    ans=s[0];
    for(ll i=1; i<n; i++){
        string fro_ans;
        if(ans.size()>s[i].size())fro_ans=ans.substr(ans.size()-s[i].size(), s[i].size());
        else fro_ans=ans;
        string st=s[i]+"#"+fro_ans;
        ll match=pi_func(st);
        for(ll j=match; j<s[i].size(); j++)ans.push_back(s[i][j]);
    }
    cout<<ans<<endl;
}
int main()
{
    fastio;ll T = 1;
    //cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

