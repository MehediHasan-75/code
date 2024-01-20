
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
    vector<ll>a(n), b(n);
    for(auto &it: a)cin>>it;
    for(auto &it: b)cin>>it;
    vector<ll>dif(n);
    ll mx=INT64_MIN;
    for(ll i=0; i<n;  i++){
        ll d=a[i]-b[i];
        dif[i]=d;
        mx=max(d, mx);
    }
    vector<ll>ans;
    for(ll i=0; i<n; i++){
        if(dif[i]==mx)ans.push_back(i+1);
    }
    cout<<ans.size()<<endl;
    prnt(ans);
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

