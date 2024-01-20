
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
   string s[n];
   for(auto &it: s)cin>>it;

   ll ans=0;
   for(ll i=0; i<n; i++){
    for(ll j=i; j<n; j++){
        ll l=s[i][j];
        ll l1=s[n-1-j][i];
        // cout<<l<<" "<<l1<<" "<<h<<" "<<h1<<endl;
        ll mx=max({l1, l});
        ans+=mx-l1;
        ans+=mx-l;
        // ans+=mx-h1;
        // ans+=mx-h;
    }
   }
   cout<<ans<<endl; 
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

