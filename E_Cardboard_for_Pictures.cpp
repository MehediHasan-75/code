
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define ii __int128_t
typedef long long ll;
typedef vector<ll> vll;
const ll N = 2e5 + 10, inf=2e18;
ll mod = 1000000007;
#define ii __int128_t
void solve(ll tc)
{
    ll n, c;
    cin>>n>>c;
    // cout<<n<<" "<<c<<endl;
    ii a=0, aa=0;
    for(ll i=0; i<n; i++){
        ll x;
        cin>>x;
        a+=x;
        aa+=x*x;
    }
    ll w=0;
    ii hi=1e12, lo=0, mid, ans;
    while(hi>=lo){
         mid=(hi+lo)/2;
        if((4*n*mid*mid+4*a*mid+aa-c)<=0){
            lo=mid+1;
            ans=mid;
        }
        else hi=mid-1;
    }
    cout<<(ll)ans<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

