
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
    ll mx=-1;
    vector<ll>v(n);
    for(auto &it:v)cin>>it;
    sort(all(v));
    //prnt(v);
    if(n==1){
        cout<<0<<endl;;
        return;
    }
    ll cnt=1;
    for(ll i=0; i<n-1; i++){
        cnt=1;
        while(i+1<n and v[i+1]<=v[i]+k)cnt++, i++;
        mx=max(cnt, mx);
    }
    cout<<n-mx<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

