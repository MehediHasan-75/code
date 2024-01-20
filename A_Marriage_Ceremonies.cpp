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
const int mxN=(1<<16);
ll arr[20][20], n, memo[20][mxN];
ll dp(ll row, ll mask){
    if(row==n){
        return 0;
    }
    if(memo[row][mask])return memo[row][mask];
    ll mx=0;
    for(ll j=n-1; j>=0; j--){
        if(!(mask&(1<<j))){
            mx=max(mx, arr[row][j]+dp(row+1, mask|(1<<j)));
        }
    }
    return memo[row][mask]=mx;
}
void solve(ll tc)
{
    cout<<"Case "<<tc<<": ";
    cin>>n;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    cout<<dp(0, 0)<<endl;
    memset(memo, 0, sizeof(memo));
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

