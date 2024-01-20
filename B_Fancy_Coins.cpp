
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
    //cout<<tc<<endl;
    ll m, ak, na1, nak;
    cin>>m>>ak>>na1>>nak;
    ll need1=m%ak, needak=m/ak;
    if(need1<=na1){
        //cout<<"first ";
        na1-=need1;
        //cout<<na1<<" ";
        needak-=na1/ak;
        cout<<max(0ll, needak-nak)<<endl;
    }
    else{
        ll ans=need1-na1;
        ans+=max(0ll, needak-nak);
        cout<<ans<<endl;
    }
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

