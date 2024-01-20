
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
    pair<ll,ll>p;
    p={1, n};
    for(ll i=1; i*i<=n; i++){
        if(n%i==0){
            p={i, n/i};
        }
    }
    ll cnt=0, mi=INT64_MIN;
    while(p.first){
        p.first/=10;
        cnt++;
    }
    mi=max(cnt, mi);
    cnt=0;
    while(p.second){
        p.second/=10;
        cnt++;
    }
    cout<<max(mi,cnt)<<endl;
}
int main()
{
    fastio;ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

