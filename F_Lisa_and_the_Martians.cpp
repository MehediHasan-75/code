
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
    ll n, k;
    cin>>n>>k;
    vector<pair<ll,ll>>v(n);
    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        v[i]={a, i+1};
    }
    sort(all(v), greater<pair<ll,ll>>());
    // vector<ll>andd(n-1);
    ll ind1, ind2, mx=-1;
    for(ll i=1; i<n; i++){
       ll andd =v[i-1].first&v[i].first;
       if(andd>mx){
        mx=andd;
        ind1=v[i-1].second;
        ind2=v[i].second;
       }
    }
    ll x=0;
    for(ll i=k-1; i>=0; i--){
        ll mask=(1ll<<i);
        if(!(mask&mx))x|=mask;
    }
    cout<<min(ind1, ind2)<<" "<<max(ind2, ind1)<<" "<<x<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

