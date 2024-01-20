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

ll func(vector<ll>&v, vector<ll>&mrk,ll sum, ll k){
    if(sum==0)return 1;
    if(sum<0)return 0;

    ll ans=0;
    for(ll i=0; i<v.size(); i++){
        if(mrk[v[i]]>0){
            mrk[v[i]]--;
            ans+=func(v, mrk, sum-v[i], k);
            mrk[v[i]]++;
        }
    }
    return ans;
}
void solve(ll tc)
{
    ll n, k;
    cin>>n>>k;

    vector<ll>v(n), mrk(501, k);
    for(auto &it: v)cin>>it;

    cout<<func(v, mrk, k, k)<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

