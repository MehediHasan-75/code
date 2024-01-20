
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
    // cout<<n<<endl;
    vector<ll>v(n, 0);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    // prnt(v);
    string s;
    cin>>s;
    // cout<<s<<endl;
    ll xoz=0, xoon=0, q;
    vector<ll>prexoz(n+2, 0), prexoon(n+2, 0);
    for(ll i=0; i<s.size(); i++){
        if(s[i]=='0'){
            xoz^=v[i];
            prexoz[i+1]=v[i];
        }
        else{
            xoon^=v[i];
            prexoon[i+1]=v[i];
        }
    }
    // prnt(prexoon);
    for(ll i=1; i<=n; i++){
        prexoz[i]^=prexoz[i-1];
        prexoon[i]^=prexoon[i-1];
    }
    cin>>q;
    while(q){
        ll type;
        cin>>type;
        if(type==2){
            ll fl;
            cin>>fl;
            if(fl)cout<<xoon<<" ";
            else cout<<xoz<<" ";
        }
        else{
            ll l, r;
            cin>>l>>r;
            ll ze=prexoz[r]^prexoz[l-1],on=prexoon[r]^prexoon[l-1];
            xoz^=ze, xoon^=on;
            xoz^=on, xoon^=ze;
        }
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

