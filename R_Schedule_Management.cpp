
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
bool func(ll m, ll time, map<ll,ll>&mp){
    ll rem=0, extra=0;
    for(ll i=1; i<=m; i++){
        ll num=mp[i];
        if(num>=time){
            rem+=num-time;
        }
        else{
            extra+=(time-num)-(time-num)%2;
        }
    }
    //cout<<rem<<" "<<extra<<endl;
    extra/=2;
    return extra>=rem;
}
void solve(ll tc)
{
    ll n, m;
    cin>>m>>n;
    map<ll,ll>mp;
    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        mp[a]++;
    }
    ll hi=1e9+10, lo=0, ans=-1;
    while(hi>=lo){
        ll mid=(hi+lo)>>1;
        if(func(m, mid, mp)){
            ans=mid;
            hi=mid-1;
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

