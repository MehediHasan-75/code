
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 2e5 + 10, inf=2e18;
#define mod 1000000007
ll pwr(ll base, ll power){
    if(power==0)return 1ll;
    ll num=pwr(base, power/2)%mod;
    if(power%2)return(((num*num)%mod)*base)%mod;
    return (num*num)%mod;
}
void solve(ll tc)
{
    ll n;
    cin>>n;
    if(n<=3){
        cout<<n<<endl;
        return;
    }
    ll ans;
    if(n%3==1){
        ans=4;
        ans*=pwr(3, max(n/3-1, 0ll))%mod;
        ans%=mod;
    }
    else if(n%3==2){
        ans=2;
        ans*=pwr(3, max(n/3, 0ll));
        ans%=mod;
    }
    else ans=pwr(3, n/3);
    cout<<ans%mod<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

