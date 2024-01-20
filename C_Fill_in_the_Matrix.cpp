
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
    ll n, m;
    cin>>n>>m;
    vector<ll>v;
    for(ll i=m-1; i>=0; i--)v.push_back(i);
    if(m==1){
        cout<<0<<endl;
        while(n--)cout<<0<<endl;
        return;
    }
    if(n==1){
        cout<<2<<endl;
        prnt(v);
        return;
    }
    ll x=min(m-1, n);
    cout<<x+1<<endl;
    for(ll i=1; i<=x; i++){
        rotate(v.begin(), v.begin()+1, v.end());
        prnt(v);
    }
    ll rem=n-x;
    while(rem--){
        prnt(v);
    }
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

