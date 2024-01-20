
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
    ll n, w, h;
    cin>>n>>w>>h;
    vector<ll>ww(n), hh(n);

    for(auto &it: ww)cin>>it;
    for(auto &it: hh)cin>>it;

    if((ww.front()>hh.front())){
        ll mx=INT64_MIN;
        for(ll i=0; i<n; i++){
            mx=max(mx, (ww[i]-w)-(hh[i]-h));
        }
        // cout<<"Mx = right "<<mx<<endl;
        for(ll i=0; i<n; i++){
            if(ww[i]+w<hh[i]+h+mx){
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
    }
    else{
        ll mx=INT64_MIN;
        for(ll i=0; i<n; i++){
            mx=max(mx, (hh[i]+h)-(ww[i]+w));
        }
        // cout<<"Mx = left "<<mx<<endl;
        for(ll i=0; i<n; i++){
            if(ww[i]-w>hh[i]-h-mx){
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
    }
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

