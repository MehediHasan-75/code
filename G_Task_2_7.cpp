
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define prnt(x)            \
    for (auto &it : x)     \
        cout << it << " "; \
    cout << "\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 2e5 + 10, inf = 2e18;
ll mod = 1000000007;
void solve(ll tc)
{
    cout << "Case " << tc << ": ";
    ll a, b, l;
    cin >> a >> b >> l;

    a = (a * b) / __gcd(a, b);

    if (l % a)
    {
        cout << "impossible\n";
    }
    else
    {
        if(a==l)cout<<1<<"\n";
        else{
            vector<ll>primes;
            ll n=a;
            for(ll i=2; i*i<=n; i++){
                if(a%i==0){
                    primes.push_back(i);
                    while(a%i==0)a/=i;
                }
            }
            if(a>0)primes.push_back(a);
            for(auto &it: primes)cout<<it<<endl;
        }
    }
}
int main()
{
    fastio;
    ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)
        solve(i);
    return 0;
}
