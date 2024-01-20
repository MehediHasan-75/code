
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
    vector<ll>v(n);
    ll ans=0, mx=0;
    for(ll i=0; i<n; i++){
        cin>>v[i];
        ans+=v[i];
    }
    sort(all(v));
    //prnt(v);
    ll l=0, r=n-1;
    while(k--){
        ans-=v[r--];
    }
    mx=ans;
    for(;r>l and r+1<n and l+1<n ;l+=2, r++){
        //add
        ans+=v[r+1];
        //remove
        ans-=v[l]+v[l+1];
        mx=max(mx, ans);
    }
    cout<<mx<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

