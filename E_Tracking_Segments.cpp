
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
    vector<pair<ll, ll>>v(m);
    for(ll i=0; i<m; i++){
        cin>>v[i].first>>v[i].second;
    }
    ll q;
    cin>>q;
    vector<ll>qq(q);
    for(auto &it: qq)cin>>it;
    auto it=[&](ll upto){
        vector<ll>cnt(n+5, 0);
        for(ll i=0; i<upto; i++){
            cnt[qq[i]]++;
        }
        for(ll i=1; i<=n; i++){
            cnt[i]+=cnt[i-1];
        }
        for(ll i=0; i<m; i++){
            ll l=v[i].first, r=v[i].second;
            ll ones= cnt[r] - cnt[l-1], zeros=(r-l+1)-ones;
            if(ones>zeros)return true;
        }
        return false;
    };
    ll ans=-1;
    ll lo=1, hi=q;
    while(hi>=lo){
        ll mid=(hi+lo)/2;
        if(it(mid)){
            hi=mid-1;
            ans=mid;
        }
        else lo=mid+1;
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

