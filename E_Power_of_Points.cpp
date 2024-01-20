
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
    map<ll,ll>mp;
    vector<ll>mi(n+2, 0), pl(n+2, 0);
    vector<pair<ll,ll>>v(n);
    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;;
        v[i]={a, i};
    }
    sort(all(v));
    ll sm=0;
    for(ll i=1; i<=n; i++){
        sm-=v[i-1].first;
        mi[i]=sm;
    }
    sm=0;
    for(ll i=n; i>0; i--){
        sm+=v[i-1].first;
        pl[i]=sm;
    }
    vector<ll>ans(n);
    for(ll i=1; i<=n; i++){
        ll cal=(mi[i]+v[i-1].first*i+i)+(pl[i]+(n-i)-v[i-1].first*(n-i+1));
        ans[v[i-1].second]=cal;
    }   
    prnt(ans);
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

