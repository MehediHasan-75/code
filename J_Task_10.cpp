
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
    ll n, mx=-1;
    cin>>n;

    string a, b, ans;
    cin>>a;
    map<string , ll>mp;
    for(ll i=0; i<n; i++){
        b=a.substr(i, 2);
        mp[b]++;

        if(mp[b]>mx){
            mx=mp[b];
            ans=b;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    fastio;ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

