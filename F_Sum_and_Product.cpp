
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
    ll arr[n];
    map<ll,ll>mp;
    for(ll i=0; i<n; i++)
    {
       cin>>arr[i];
       mp[arr[i]]++;
    }
    ll q;
    cin>>q;
    while(q--){
        ll x, y;
        cin>>x>>y;
        ll sqpl= x*x - 4*y;
        if(sqpl<0){
            cout<<0<<" ";
            continue;
        }
        ll sqplsqrt=sqrt(sqpl);
        if(sqplsqrt*sqplsqrt!=sqpl){
            cout<<0<<" ";
            continue;
        }
        ll a=(sqplsqrt+x)/2;
        ll b=x-a;
        ll ans=0;
        if(a==b){
            if(mp.count(a)){
                ans=(mp[a]*(mp[a]-1))/2;
            }
        }
        else{
            if(mp.count(a) and mp.count(b)){
                ans=mp[a]*mp[b];
            }
        }
        cout<<ans<<" ";
    }
    cout<<endl;
    
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

