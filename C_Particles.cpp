
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
    vector<ll>v(n+1);
    ll mx=INT64_MIN, po=0;
    for(ll i=1; i<=n; i++){
        cin>>v[i], mx=max(mx, v[i]);
         if(v[i]>=0)po=1;
    }
    if(!po){
        cout<<mx<<endl;
        return;
    }
    ll ans1=0, ans2=0;
    for(ll i=1; i<=n; i++){
        if(i%2)ans1+=max(0ll, v[i]);
        else ans2+=max(0ll, v[i]);
    }
    cout<<max(ans1, ans2)<<endl;
    
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

