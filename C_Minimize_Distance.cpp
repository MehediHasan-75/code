
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
    vector<ll>vp, vn;
    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        if(a<=0)vn.push_back(-a);
        else vp.push_back(a);
    }
    sort(all(vp));
    sort(all(vn));
    ll cnt=0;
    for(ll i=vp.size(); i>=1; i-=k){
        cnt+=vp[i-1];
    }
    //cout<<cnt<<endl;
    for(ll i=vn.size(); i>=1; i-=k){
        cnt+=vn[i-1];
    }
    ll p=0, nn=0;
    if(vp.size())p=vp.back();
    if(vn.size())nn=vn.back();
   // cout<<cnt<<" "<<max(p,nn)<<endl;
    cout<<cnt*2-max(p,nn)<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

