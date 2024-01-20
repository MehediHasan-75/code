
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

vector<ll> factors;
void primefactor(ll n)
{
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
                factors.push_back(i);
            }
        }
    }
    if (n > 1)
        factors.push_back(n);
}
void solve(ll tc)
{
    factors.clear();

    ll n;
    cin>>n;

    primefactor(n);

    // for(auto &it: factors)cout<<it<<" ";
    // cout<<endl;

    if(factors.size()<2)cout<<-1<<endl;
    else{
        ll a=factors[0], b=1;

        for(ll i=1; i<factors.size(); i++)b*=factors[i];

        ll c=1;

        set<ll>st;
        st.insert(a);
        st.insert(b);
        st.insert(c);

        if(st.size()==3)cout<<a<<" "<<b<<" "<<c<<endl;
        else cout<<-1<<endl;
    }
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

