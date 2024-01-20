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
ll f(ll hn, vector<ll>&h, vector<ll>&c){
    ll total=0;
    for(ll i=0; i<h.size(); i++){
        total+=abs(hn-h[i])*c[i];
    }
    //cout<<total<<endl;
    return total;
}
ll ternary_search(ll l, ll r, vector<ll>&h, vector<ll>&c) {
    
    while (r-l>=1 ) {
        
        ll m1 = l + (r - l) / 3,m2 = r - (r - l) / 3;
        
        ll f1 = f(m1, h, c), f2 = f(m2, h, c);
        if (f1 > f2)
            l = m1+1;
        else
            r = m2-1;
    }
    //cout<<l<<" "<<r<<endl;
    ll mi=f(l, h, c);
    for(ll i=l; i<=r; i++)mi=min(f(i, h, c),mi);
    return mi;
}
void solve(ll tc)
{
    ll n;
    cin>>n;
    vector<ll>h(n), c(n);
    for(auto &it: h)cin>>it;
    for(auto &it: c)cin>>it;
    cout<<ternary_search(1, 100000, h, c)<<endl;
    // for(ll i=1; i<=3; i++){
    //     cout<<f(i, h, c)<<" ";
    // }
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}