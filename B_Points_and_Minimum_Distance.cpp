
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
    vector<ll>v(n*2);
    for(ll i=0; i<2*n; i++){
      cin>>v[i];
    }
    sort(all(v));

    ll ans=0;
    vector<ll>x, y;
    ll prev=v[0];
    for(ll i=0; i<n; i++){
        x.push_back(v[i]);
        ans+=v[i]-prev;
        prev=v[i];
    }
    prev=v[n];
    for(ll i=n; i<2*n; i++){
        y.push_back(v[i]);
        ans+=v[i]-prev;
        prev=v[i];
    }
    cout<<ans<<endl;
    for(ll i=0; i<n; i++){
        cout<<x[i]<<" "<<y[i]<<endl;
    }
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

