
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
    vector<ll>v[n], vv;
    for(ll i=0; i<n; i++){
        ll x;
        cin>>x;
        for(ll j=0; j<x; j++){
            ll a;
            cin>>a;
            v[i].push_back(a);
            vv.push_back(a);
        }
    }
    map<ll,ll>mrk;

    sort(all(vv), greater<ll>());
    ll cnt=0;
    for(auto &it: vv){
        mrk[it]= cnt++;
    }
    // prnt(vv);
    ll split=0;
    for(auto &it: v){
        for(ll i=1; i<it.size(); i++){
            if(mrk[it[i-1]]!=mrk[it[i]]+1) split++;
        }
    }
    cout<<split<<" "<<n+split-1<<endl;
}
int main()
{
    fastio;ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

