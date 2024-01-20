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
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T>
using order_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
void solve(ll tc)
{
    ll n;
    cin>>n;
    vector<ll>a(n), b(n);
    order_set<ll>st;
    for(auto &it: a)cin>>it, st.insert(it);
    for(auto &it: b)cin>>it;
    // sort(all(a));
    sort(all(b));
    ll mul=1;
    for(ll i=n-1; i>=0; i--){
        ll num=st.order_of_key(b[i]+1);
        num=st.size()-num;
        num%=mod;
        mul=((mul%mod)*num)%mod;
        st.erase(st.rbegin());
    }
    cout<<mul%mod<<endl;
}
int main()
{
    fastio;
    ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)
    {
        solve(i);
    }
    return 0;
}