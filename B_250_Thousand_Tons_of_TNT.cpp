
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

vector<ll> divisors;
ll divisor=0;
void div_cnt(ll n)
{
    for (ll i = 1; i * i <= n; i++) {
    if (i * i == n) {
         divisor += 1;
         divisors.push_back(i);
    }
          else if (n % i == 0) {
        divisor += 2;
        divisors.push_back(i), divisors.push_back(n/i);
    }
  }
}
void solve(ll tc)
{
    ll n;
    cin>>n;
    ll mx=INT64_MIN, mi=INT64_MAX, sm=0, ans=0;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    divisors.clear();

    div_cnt(n);

    for(auto &it: divisors){
        mx=INT64_MIN, mi=INT64_MAX;
        for(ll i=0; i<n; i+=it){
            ll sm=0;
            for(ll j=i; j<i+it; j++){
                sm+=v[j];
            }
            mi=min(mi, sm);
            mx=max(mx, sm);
        }
        ans=max(ans, mx-mi);
    }
    cout<<ans<<endl;

}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

