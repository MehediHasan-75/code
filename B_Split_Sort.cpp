
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
    vector<pair<ll,ll>>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i].first;
        v[i].second=i;
    }
    sort(all(v));
    // for(auto &it: v)cout<<it.first<<" "<<it.second<<endl;
    ll cnt=0;
    for(ll i=1; i<n; i++){
        if(v[i].second<v[i-1].second){
            // cout<<v[i-1].first<<endl;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    // cout<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

