
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
    ll xo=0;
    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        xo^=a;
    }
    ll mi=xo, mx=xo, orr=0;
    vector<ll>v(m);
    for(ll i=0; i<m; i++){
        cin>>v[i];
        orr|=v[i];
    }
    if(n%2==0){
        cout<<(mi&(~orr))<<" "<<mx<<endl;
    }
    else{
        cout<<mi<<" "<<(mx|orr)<<endl;
    }
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

