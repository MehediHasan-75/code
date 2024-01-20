
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
//this algorithm find's x, y such that ax+by=gcd(a, b);
// we know gcd(a, b)=gcd(b, a%b) so ax+by= bx1+(a-a/b *b)y1= ay1+b(x1-a/b*y1)
// so, x=y1, and y=x1-a/b*y1 and as gcd(a, 0)=a, ax+0y=a. so base case is x=1 and y=anything.
pair<ll,ll> Extended_gcd(ll a, ll b){
    if(b==0)return {1, 1};
    auto [x1, y1]=Extended_gcd(b, a%b);
    ll x=y1, y=x1-(a/b)*y1;
    return {x, y};
}
// gcd(a, m) = 1 is also the condition for the modular inverse to exist.
//ax+my=1 mod m so ax=1 mod m. so here x is modular inverse of a.
void solve(ll tc)
{
    ll a, b;
    cin>>a>>b;
    auto it=Extended_gcd(a,b);
    cout<<it.first<<" "<<it.second<<endl;
}
int main()
{
    fastio;ll T = 1;
    //cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

