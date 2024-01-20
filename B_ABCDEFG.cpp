
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
    char x, y;
    cin>>x>>y;
    vector<ll>v={0, 3, 1, 4, 1, 5, 9};
    for(ll i=1; i<=v.size(); i++)v[i]=v[i-1]+v[i];
    // prnt(v);
    ll a=x-'A', b=y-'A';
    //<<a<<" "<<b<<endl;
    // cout<<v[b]<<" "<<v[a]<<endl;
    if(a==0 or b==0)cout<<v[max(a,b)]<<endl;
    else cout<<v[max(a,b)]-v[min(a,b)]<<endl;
}
int main()
{
    fastio;ll T = 1;
    //cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

