
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
map<char, ll>mp;
void solve(ll tc)
{
    for(char ch='A'; ch<='Z'; ch++)mp[ch]=ch-'A'+1;
    // for(auto &it: mp)cout<<it.first<<" "<<it.second<<endl;
    string s;
    cin>>s;
    ll val=0;
    for(ll i=0; i<s.size(); i++){
        val=val*26+mp[s[i]];
    }
    cout<<val<<endl;
}
int main()
{
    fastio;ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

