
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
    ll n;
    cin >> n;
    vector<ll> v(n);
    map<ll,ll>mp;
    ll mx = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    ll ans;
    if (mp[0] == 1)
    {
        for(ll i=1; ; i++){
           if(mp[i]==0){
            cout<<i<<endl;
            cout.flush();
            break;
           } 
        }
    }
    else
    {
        cout << 0 << endl;
        cout.flush();
    }
    ll y;
    while(1){
        cin>>y;
        if(y==-1)break;
        cout<<y<<endl;
        cout.flush();
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
