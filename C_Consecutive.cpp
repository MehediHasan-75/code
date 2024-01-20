
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
    string s;
    ll n, q;
    cin>>n>>q;

    cin>>s;
    // cout<<s<<endl;
    vector<ll>v(n+1, 0);

    for(ll i=1; i<n; i++){
        if(s[i]==s[i-1]){
            v[i]+=v[i-1]+1;
        }
        else v[i]+=v[i-1];
    }
    for(ll i=n; i>0; i--){
        v[i]=v[i-1];
    }

    // prnt(v);
    while(q--){
        ll l, h;
        cin>>l>>h;

        cout<<v[h]-v[l]<<endl;
    }
    
}
int main()
{
    fastio;ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

