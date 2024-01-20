
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
    ll a=0, o=0;
    vector<ll>v(n);
    for(auto &it: v)cin>>it;
    for(ll i=0; i<n; i++){
        ll cnt=0;
        while(i<n and v[i])cnt++, i++;
        a=max(a, cnt);
    }
    for(auto &it: v)cin>>it;
    for(ll i=0; i<n; i++){
        ll cnt=0;
        while(i<n and v[i])cnt++, i++;
        o=max(o, cnt);
    }
    if(o==a)cout<<"Draw\n";
    else if(o<a)cout<<"Om\n";
    else cout<<"Addy\n";
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

