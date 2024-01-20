
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
    ll n;
    cin>>n;

    map<ll,ll>mp;
    ll times, power;
    cin>>power>>times;
    ll mx=0;
    for(ll i=0; i<n-1; i++){
        ll a, b;
        cin>>a>>b;
        if(b>=times)mx=max(mx, a);
    }
    if(mx>=power)cout<<-1<<endl;
    else cout<<mx+1<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

