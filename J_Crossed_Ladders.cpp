
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
double eps = 1e-10;
#define precision(n) cout << setprecision(n) << fixed;
typedef long double ld;
void solve(ll tc)
{
    cout<<"Case "<<tc<<": ";
    ld x, y, c;
    cin>>x>>y>>c;
    double lo=0, hi=min(x,y);
    ll cnt=100;
    while(hi-lo>=eps){
        ld m=(hi+lo)/2.0;
        ld a=sqrtl((x*x)-(m*m)), b=sqrtl((y*y)-(m*m)), c1=(a*b)/(a+b);
        if(c1<=c){
            hi=m;
        }
        else lo=m;
    }
    precision(10);
    cout<<lo<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

