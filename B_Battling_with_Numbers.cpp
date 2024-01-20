
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 2e6 + 10, inf=2e18;
ll mod = 998244353;
vector<ll>cnt1(N, 0), cnt2(N, 0);
ll pwr(ll a,ll b)
{
    if(b==0) return 1;
    if(b%2==0) 
    {
        ll ret=pwr(a,b/2)%mod;
        return ((ret)*(ret))%mod;
    }
    else return ((a)*(pwr(a,b-1)%mod))%mod;
    
}
void solve(ll tc)
{
    ll n;
    cin>>n;
    vector<ll>v(N);
    for(ll i=0; i<n; i++)cin>>v[i];

    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        cnt1[v[i]]+=a;
    }
    // for(ll i=0; i<n; i++)cout<<v[i]<<endl;
    ll m;
    cin>>m;
    for(ll i=0; i<m; i++)cin>>v[i];

    for(ll i=0; i<m; i++){
        ll a;
        cin>>a;
        cnt2[v[i]]+=a;
    }

    ll cnt=0;
    for(ll i=0; i<N; i++){
        ll dif=cnt1[i]-cnt2[i];
        if(dif<0){
            cout<<0<<endl;
            return;
        }
        if(dif>0)cnt++;
    }
    cout<<pwr(2, cnt)<<endl;
}
int main()
{
    fastio;ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

