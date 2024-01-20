
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
    ll q;
    cin>>q;

    ll l=-1, r=INT64_MAX;
    set<ll>st;

    while(q--){
        ll type, a;
        cin>>type>>a;

        if(type==1){
            l=max(l, a);
        }
        else if(type==2){
            r=min(r, a);
        }
        else st.insert(a);
    }
    ll ans=r-l+1;

    for(auto &it: st){
        if(it>=l and it<=r)ans--;
    }
    cout<<max(0ll, ans)<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

