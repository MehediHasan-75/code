
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
ll n;
vector<ll>v(5005);
bool chk(ll need){
    ll can=0;
    for(ll d=1; d<=(n+1)/2; d++){
        ll cnt=0, sm=0, fl=0, j;
        for( j=0; j<n; j++){
            if(cnt==d){
                cnt=0;
                continue;
            }
            else{
                sm+=v[cnt];
                cnt++;
            }
        }
        // if(j!=n){
        //     sm+=v[cnt];
        // }
        // if(fl==0)sm+=v[cnt];
        // cout<<"sm = "<<sm<<" d= "<<d<<endl;
        can=max(can, sm);
    }
    return can>=need;
}
void solve(ll tc)
{
    cin>>n;
    for(ll i=0; i<n; i++)cin>>v[i];
    // for(ll i=1; i<n; i++)v[i]+=v[i-1];
    ll ans=0, lo=0, hi=1e18;
    while(hi>=lo){
        ll mid=(hi+lo)>>1;
        if(chk(mid)){
            ans=mid;
            lo=mid+1;
        }
        else hi=mid-1;
    }
    cout<<ans<<endl;
    // cout<<chk(5100000001);
}
int main()
{
    fastio;ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

