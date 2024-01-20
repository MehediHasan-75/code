
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
bool chk(vector<ll> &v, ll g, ll k){
    ll sm=0;
    for(ll i=0; i<v.size(); i++){
        sm+=min(g, v[i]);
    }
    return (sm/g)>=k;
}
void solve(ll tc)
{
    ll n, k;
    cin>>n>>k;
    //cout<<n<<" "<<k<<endl;
    vector<ll>v(n);
    for(auto &it: v)cin>>it;
    //sort(all(v), greater<ll>());
    //prnt(v);
    ll hi=1e14, lo=1, ans=0;
    while(hi>=lo){
        ll mid=(hi+lo)>>1;
        //cout<<"in ";
        if(chk(v,mid, k)){
            ans=mid;
            lo=mid+1;
        }
        else hi=mid-1;
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

