
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
    ll n;
    cin>>n;
    map<pair<string , string>, string>mp;
    for(ll i=0; i<n; i++){
        vector<string>v(3);
        for(ll j=0; j<3; j++){
            cin>>v[j];
        }
        // prnt(v);
        mp[{v[0], v[1]}]=v[2];
    }
    ll q;
    cin>>q;
    // cout<<q<<endl;
    while(q--){
        string x, y;
        cin>>x>>y;
        cout<<mp[{x, y}]<<"\n";
    }
}
int main()
{
    fastio;ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

