
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
    vector<ll>a(k), t(n+2, INT_MAX);
    for(auto &it: a)cin>>it;
    for(ll i=0; i<k; i++){
        ll x;
        cin>>x;
        t[a[i]]=x;
    }
    //prnt(t);
    vector<ll>fr(n+1, INT_MAX), bc(n+2, INT_MAX);
    ll p=INT_MAX;
    for(ll i=1; i<=n; i++){
        p=min(p+1, t[i]);
        fr[i]=p;
    }
    p=INT_MAX;
    for(ll i=n; i>0; i--){
        p=min(p+1, t[i]);
        bc[i]=p;
    }
    for(ll i=1; i<=n; i++)cout<<min(fr[i], bc[i])<<" ";
    cout<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

