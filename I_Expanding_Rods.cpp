
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
double eps = 1e-4;
#define precision(n) cout << setprecision(n) << fixed;
typedef long double ld;
void solve(ll tc)
{
    cout<<"Case "<<tc<<": ";
    ld l, n, c;
    cin>>l>>n>>c;
    ld s=(1.+n*c)*l;
    ld lo=0, hi=(l)/2.,m, ans=0;
    ll cnt=100;
    while(cnt--){
        ld h=(hi+lo)/2.,r=(2.*l*l+8.*h*h)/(16.*h),  th=2.*asin((l/(2.*r)));
        ld l_temp=2*r*sin(s/(2*r));
        if(l_temp>l)lo=h;
        else hi=h;
        
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

