
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
    vector<ll>v1(n), v2(n);
    ll mi1=INT64_MAX, mi2=INT64_MAX, sm1=0, sm2=0;

    for(auto &it: v1)cin>>it, mi1=min(it, mi1), sm1+=it;
    for(auto &it: v2)cin>>it, mi2=min(it, mi2), sm2+=it;

    cout<<min(mi1*n+sm2, mi2*n+sm1)<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

