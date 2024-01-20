#include <bits/stdc++.h>  
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
typedef pair<int,int> pin;
typedef pair<ll,ll> pll;
typedef pair<double,double> pd;
 
typedef vector<ll> vll;
typedef vector<int> vin;
 
typedef vector<vector<int> >vvin;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pll> > vvpll;
 
typedef vector<pll> vpll;
typedef vector<pin> vpin;
 
ll mod = 100000007;
double eps = 1e-12;
#define inf 2e18
const int N=1e6+10;
#define pi acos(-1.0)
#define numset(x) __builtin_popcountll(x)
 
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
 
#define mpa make_pair
#define pb push_back
#define fi first
#define se second
#define lb  lower_bound
 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define precision(n) cout << setprecision(n)<<fixed;
 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
 
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
ll dp[1005][1005], n;
vector<ll> arr(200), brr(200);
ll func(ll val, ll ind)
{
    ll ans1=0, ans2=0;
    if(val==0)return 1;
    if(ind==n)return 0;
    if(dp[val][ind]!=-1)return dp[val][ind];
    for(ll i=1; i<=brr[ind]; i++)
    {
        if(val-arr[ind]*i>=0)ans1+=func(val-arr[ind]*i, ind+1 );
    }
    ans2+=func(val, ind+1);
    //cout<<val<<" ";
    return dp[val][ind]=(ans1+ans2)%mod;
}
void solve(ll i)
{
    ll val;
    cin>>n>>val;
    cout<<"Case "<<i<<": ";
    memset(dp, -1, sizeof(dp));
    for(ll i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(ll i=0; i<n; i++)
    {
        cin>>brr[i];
    }
    cout<<func(val, 0)%mod<<endl;
     arr.clear(), brr.clear();
}
int main()
{
    fastio;
    ll T=1;
    cin >> T;
    for(ll i=1;i<=T;i++) {
        solve(i);
    }
    return 0;
}