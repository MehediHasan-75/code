
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
    ll n;
    cin>>n;
    ll po=0, ne=0;
    vector<ll>v(n);
    pair<ll,ll>mx={0, 0};
    for(ll i=0; i<n; i++){
        cin>>v[i];
        if(v[i]<0){
            ne=1;
            if(abs(v[i])>mx.first){
                mx={abs(v[i]), -(i+1)};
            }
        }
        else if(v[i]>0){
            po=1;
            if(v[i]>mx.first){
                mx={v[i], i+1};
            }
        }
    }
    if(po==0){
        cout<<n-1<<endl;
        for(ll i=n-1;i>0;  i--){
            cout<<i<<" "<<i+1<<endl;
        }
    }
    else if(ne==0){
        cout<<n-1<<endl;
        for(ll i=2; i<=n; i++){
            cout<<i<<" "<<i-1<<endl;
        }
    }
    else{
        vector<pair<ll,ll>>vv;
        if(mx.second<=0){
            ll ind=-mx.second;
            for(ll i=0; i<n; i++){
                if(v[i]>0){
                    vv.push_back({i+1, ind});
                }
            }
            for(ll i=n-1;i>0;  i--){
                vv.push_back({i, i+1});
            }
        }
        else{
            ll ind=mx.second;
            for(ll i=0; i<n; i++){
                if(v[i]<0){
                    vv.push_back({i+1, ind});
                }
            }
            for(ll i=2; i<=n; i++){
                vv.push_back({i, i-1});
            }
        }
        cout<<vv.size()<<endl;
        for(auto &it: vv)cout<<it.first<<" "<<it.second<<endl;
    }
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

