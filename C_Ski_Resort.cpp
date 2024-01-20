
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
    ll n, d, can;
    cin>>n>>d>>can;
    ll ans=0, cnt=0;
    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        if(a<=can)cnt++;
        else{
            ll x=cnt-(d-1);
            cnt=0;
            if(x<0)continue;
            ans+=(x*(x+1))/2;
        }
    }
    ll x=cnt-(d-1);
    if(x>0)ans+=(x*(x+1))/2;
    cout<<ans<<endl;

}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

