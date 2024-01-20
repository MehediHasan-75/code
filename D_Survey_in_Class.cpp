
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
    ll n, m;
    cin>>n>>m;

    vector<pair<ll,ll>>v(n);

    for(ll i=0; i<n; i++){
        cin>>v[i].first>>v[i].second;
    }

    ll ans=0;

    auto cmp1=[&](pair<ll,ll>p1, pair<ll,ll>p2){
        return p1.second<p2.second;
    };

    auto cmp2=[&](pair<ll,ll>p1, pair<ll,ll>p2){
        return p1.first<p2.first;
    };
    sort(v.begin(), v.end(), cmp1);

    ll mx=INT64_MIN;

    for(ll i=1; i<n; i++){
        ll l=v[i].first, r=v[i].second, len=r-l+1;
        ll ll=max(l, v[0].first), rr=min(r, v[0].second), x;
        x=max(0ll, rr-ll+1);

        cout<<v[0].first<<" "<<v[0].second<<endl;
        cout<<l<<" "<<r<<endl;
        cout<<x<<endl;
        len-=x;
        len=len+len;

        mx=max(len, mx);
    }
    cout<<mx<<endl;

}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

