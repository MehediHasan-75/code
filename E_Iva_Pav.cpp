
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

bool func(vector<vector<ll>>&vv, ll l, ll r, ll k){
    ll num=0;
    for(ll bit=31; bit>=0; bit--){
        ll len=r-l+1, bits=vv[r][bit] - vv[l-1][bit];
        if(bits==len)num|=(1ll<<bit);
    }
    return num>=k;
}
ll bsrch(vector<vector<ll>>&vv, ll l, ll k){
    ll lo=l, hi=vv.size()-1, ans=-1;
    while(hi>=lo){
        ll mid=(hi+lo)/2;
        if(func(vv, l, mid, k)){
            ans=mid;
            lo=mid+1;
        }
        else hi=mid-1;
    }
    return ans;
}
void solve(ll tc)
{
    ll n;
    cin>>n;
    vector<vector<ll>>vv(n+1, vector<ll>(32, 0));
    vector<ll>v(n+1);
    for(ll i=1; i<=n; i++)cin>>v[i];
    for(ll i=1; i<=n; i++){
        for(ll bit=31; bit>=0; bit--){
            vv[i][bit]+=vv[i-1][bit];
            // cout<<v[i]<<" ";
            if(v[i]&(1ll<<bit)){
                // cout<<"HI\n";
                vv[i][bit]++;
            }
        }
    }
    // for(ll i=1; i<=n; i++){
    //     for(ll bit=2; bit>=0; bit--){
    //         cout<<vv[i][bit];
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    ll q;
    cin>>q;
    while(q--){
        ll l, k;
        cin>>l>>k;
        cout<<bsrch(vv, l, k)<<" ";
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

