
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
ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
  return (a / gcd(a, b)) * b;
}
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
void solve(ll t)
{
    divisors.clear();
    ll n;
    cin>>n;

    div_cnt(n);

    ll cnt=0;

    for(auto &it: divisors){
        if(it==n)continue;
        ll b=max(n-it, it), a=min(n-it, it);
        if(b%a==0){
            cnt++;
            if(a!=b)cnt++;
        }
    }
    cout<<cnt<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <=T ; i++)solve(i);
    return 0;
}

