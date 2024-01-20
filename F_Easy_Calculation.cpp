
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
#define pi acos(-1.0)
double eps = 1e-12;
#define precision(n) cout << setprecision(n) << fixed;
typedef long double ld;
void solve(ll tc)
{
    ll a, b, c;
    cin>>a>>b>>c;
    double lo=0, hi=1e9+10;
    double ans=0;
    while(hi-lo>=eps){
        double x=(hi+lo)/2.;
        if((a*x+b*sin(x))<c)lo=x+1;
        else hi=x-1, ans=x;
    }
    precision(6);
    cout<<ans<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

