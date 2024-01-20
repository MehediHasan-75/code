
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
    vector<vector<ll>>v(n, vector<ll>(n));
    vector<ll>ans(n, (1ll<<30)-1);
   for(ll i=0; i<n; i++){
    for(ll j=0; j<n; j++){
        cin>>v[i][j];
        if(i!=j){
            ans[i]&=v[i][j];
            ans[j]&=v[i][j];
        }
    }
   }
   for(ll i=0; i<n; i++){
    for(ll j=0; j<n; j++){
        if(i==j)continue;
        if(v[i][j]!=(ans[i]|ans[j])){
            cout << "NO\n";
            return;
        }
    }
   }
   cout << "YES\n";
   prnt(ans);
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

