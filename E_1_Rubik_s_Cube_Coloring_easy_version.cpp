
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
ll pwr(ll a,ll b)
{
    if(b==0) return 1;
    if(b%2==0) 
    {
        ll ret=pwr(a,b/2)%mod;
        return ((ret)*(ret))%mod;
    }
    else return ((a%mod)*(pwr(a,b-1)%mod))%mod;
    
}
void solve(ll tc)
{
    ll n;
    cin>>n;
    cout<<((pwr(4, (1ll<<(n))-2))*6)%mod<<endl;
}
int main()
{
    fastio;ll T = 1;
    //cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}
