#include <bits/stdc++.h>
using namespace std;

#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define scanv(x) vector<ll>x(n);for(auto &it: x){cin>>it;}
#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define errprnt(x) for(auto &it: x)cerr<<it<<" ";cerr<<"\n";
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define yes cout << "yes\n";
#define no cout << "no\n";
#define case cout<<"Case "<<cas++<<": ";
#define ceil(n, k) ((n - 1) / k + 1)
#define inf 2e18
#define pi acos(-1.0)

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define precision(n) cout << setprecision(n) << fixed;
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vll;
ll mod = 1000000007;
const int N = 1e5 + 10;
double eps = 1e-12;
ll func(ll n){
    if(n==0)return 0;
    ll cnt=0, i=0;
    for( i=63; i>=0; i--){
        if(n&(1ll<<i))break;
    }
    ll x=pow(2,i);
    //cout<<x<<" "<<i<<endl;
    cnt+=(x/2)*i + n - x + 1 + func(n-x);
    return cnt;
}
void solve(ll tc)
{
    ll n;
    cin>>n;
    cout<<func(n)<<endl;
}
int main()
{
    fastio;
    ll T = 1;
    //cin >> T;
    for (ll i = 1; i <= T; i++)
    {
        solve(i);
    }
    return 0;
}