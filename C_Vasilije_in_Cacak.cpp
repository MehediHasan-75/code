
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
ll func(ll n){
    return n*(n+1)/2;
}
void solve(ll tc)
{
    // cout<<tc<<endl;
    ll n, k, x;
    cin>>n>>k>>x;
    if(n<k){
        cout << "NO\n";
    }
    else{
        ll lo=func(k), hi=func(n)-func(n-k);
        // cout<<lo<<" "<<hi<<endl; 
        if(x>=lo and x<=hi)cout << "YES\n";
        else cout << "NO\n";
    }
    // cout<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

