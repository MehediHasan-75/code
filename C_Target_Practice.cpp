
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
    ll pt=1, ans=0;
    for(ll i=1; i<=10; i++){
        for(ll j=1; j<=10; j++){
            char ch;
            cin>>ch;
            if(ch=='X'){
                ll x=i, y=j;
                if(i>5) x=11-i;
                if(j>5) y=11-j;
                // cout<<i<<" "<<j<<" "<<min(x, y)<<endl;
                ans+=min(x, y);
            }
        }
    }
    cout<<ans<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

