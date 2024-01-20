
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
    ll n, w;
    cin>>n>>w;
    vector<pair<ll,ll>>v(n);
    vector<ll>ans(n);
    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        ans[i]=(a+1)/2;
        w-=ans[i];
        v[i]={a, i};
    }
    sort(v.begin(), v.end(), greater<pair<ll,ll>>());
    if(w<0)cout<<-1<<endl;
    else{
        for(ll i=0; i<n; i++){
            if(w==0)break;
            ll ind=v[i].second, val=v[i].first;
            ll can=min(w, val-ans[ind]);
            w-=can;
            ans[ind]+=can;
        }
        // cout<<has<<endl;
        for(auto &it: ans)cout<<it<<" ";
    }
}
int main()
{
    fastio;ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

