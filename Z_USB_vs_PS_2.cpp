
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
void solve(ll tc)
{
    ll a, b, c;
    cin>>a>>b>>c;

    map<string, ll> mp={{"USB", a}, {"PS/2", b}, {"b", c}};

    ll eq=0, cost=0, n;
    cin>>n;
    vector<pair<ll,string>>v(n);

    for(ll i=0; i<n; i++){
        cin>>v[i].first;
        cin>>v[i].second;
    }
    sort(v.begin(), v.end());
    for(auto &[a, b]: v){
        if(mp[b]){
            mp[b]--;
            eq++;
            cost+=a;
        }
        else if(mp["b"]){
            mp["b"]--;
            eq++;
            cost+=a;
        }
    }
    cout<<eq<<" "<<cost<<endl;
}
int main()
{
    fastio;ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

