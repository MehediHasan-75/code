
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
    map<ll,ll>mp;

    ll n, q;
    cin>>n>>q;

    vector<unordered_set<ll>>v(n);

    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        v[i].insert(a);
        // mp[i]=i;
    }
    while(q--){
        ll a, b;
        cin>>a>>b;
        a--, b--;

        if(v[a].size()> v[b].size()){
                for(auto &it: v[b]){
                    v[a].insert(it);
                }

                v[b].clear();
                swap(v[b], v[a]);
        }
        else{
            for(auto &it: v[a]){
                v[b].insert(it);
            }
            v[a].clear();
        }
        cout<<v[b].size()<<"\n";
    }

}
int main()
{
    fastio;ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

