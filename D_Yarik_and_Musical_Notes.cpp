
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
    map<ll, ll>mp, mplg;

    ll n;
    cin>>n;

    vector<ll>v(n), lg(n);
    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;

        v[i]=a;
        lg[i]=log2(a);

        mp[a]++;

        if((a&(a-1))==0){
            mplg[a-log2(a)]++;
        }
    }
    ll ans=0;

    for(ll i=0; i<n; i++){
        ll a=v[i];
        // cout<<a<<" ";

        if((a&(a-1))==0){
            ans+=(mplg[a-log2(a)])-1;
            mplg[a-(log2(a))]--;
        }
        else ans+=mp[a]-1;

        mp[a]--;
        
    }
    cout<<ans<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

