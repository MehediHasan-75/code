
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
    ll a, b;
    cin>>a>>b;

    ll a_=a, b_=b;

    ll mi=INT64_MAX, cnt=0;
    
    for(ll y=b; y>=1; y--){
        if(a%y==0){
            mi=min(mi, cnt);
        }
        cnt++;
        a++;
    }
    cnt=0;
    for(ll x=a_; x>=1; x--){
        if(x%b==0){
            mi=min(mi, cnt);
        }
        cnt++;
        b++;
    }
    cout<<mi<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

