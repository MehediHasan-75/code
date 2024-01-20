
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
    ll n, k;
    cin>>n>>k;
    ll sm=n*(n+1)/2;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
        sm-=v[i];
    }
    v.push_back(sm);
    ll ind=(k%(n+1));
    // prnt(v);
    rotate(v.begin(),  v.begin()+n-ind+1, v.end());
    for(ll i=0; i<n; i++)cout<<v[i]<<" ";
    cout<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

