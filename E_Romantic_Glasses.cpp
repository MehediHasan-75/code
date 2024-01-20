
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
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
        if(i%2)v[i]*=-1;
    }
    // prnt(v);
    ll l=0, r=0, sum=0;
    map<ll,ll>mp;
    mp[0ll]++;
    for(; r<n; r++){
        sum+=v[r];
        if(mp.count(sum)){
            cout << "YES\n";
            return;
        }
        mp[sum]++;
    }
    cout << "NO\n";
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

