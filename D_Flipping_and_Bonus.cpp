
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 5005, inf=2e18;
ll mod = 1000000007;
ll n, m;
ll bonus_per_Index[N], v[N];
ll dp[N][N];
ll func(ll ind, ll cnt){
    if(ind==n)return 0;
    if(dp[ind][cnt]!=-1)return dp[ind][cnt];
    ll mx=max((v[ind]+bonus_per_Index[cnt+1]+func(ind+1, cnt+1)), func(ind+1, 0));
    //cout<<ind<<" "<<cnt<<" "<<mx<<endl;
    return dp[ind][cnt]=mx;
}
void solve(ll tc)
{
    memset(dp, -1, sizeof(dp));
    cin>>n>>m;
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    for(ll i=0; i<m; i++){
        ll indx, bonus;
        cin>>indx>>bonus;
        bonus_per_Index[indx]=bonus;
    }
    cout<<max((v[0]+bonus_per_Index[1]+func(1, 1)), func(1, 0))<<endl;
}
int main()
{
    fastio;ll T = 1;
    //cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

