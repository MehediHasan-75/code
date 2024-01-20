
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
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
      cin>>v[i];
    }
    vll ans;
    ans.push_back(v.front());
    for(ll i=1; i<n; i++){
        if(v[i-1]<=v[i])ans.push_back(v[i]);
        else{
            ans.push_back(max(1ll,v[i]-1));
            ans.push_back(v[i]);
        }
    }
    cout<<ans.size()<<endl;
    prnt(ans);
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

