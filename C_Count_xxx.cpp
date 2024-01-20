
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
void solve(ll tc)
{
    ll n;
    cin>>n;

    map<char, ll>mp;

    string s;
    cin>>s;


    for(ll i=0; i<n; i++){
        ll cnt=1;
        char ch=s[i];
        while(i+1<n and s[i+1]==s[i])cnt++, i++;

        mp[ch]=max(cnt, mp[ch]);
    }
    ll ans=0;

    for(auto &it: mp)ans+=it.second;
    cout<<ans<<endl;
}
int main()
{
    fastio;ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

