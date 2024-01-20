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
    ll n, m, k;
    cin>>n>>m>>k;
    multiset<ll>st1, st2;
    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        st1.insert(a);
    }
    for(ll j=0; j<m; j++){
        ll a;
        cin>>a;
        st2.insert(a);
    }
    for(ll i=1; i<=min(k, 2600ll+k%2); i++){
        if(i%2==1){
            ll x= *st1.begin(), y=*st2.rbegin();

            if(x<y){
                st1.erase(st1.find(x));
                st2.erase(st2.find(y));
                st1.insert(y);
                st2.insert(x);
            }
        }
        else{
            ll x= *st1.rbegin(), y= *st2.begin();

            if(x>y){
                st1.erase(st1.find(x));
                st2.erase(st2.find(y));
                st1.insert(y);
                st2.insert(x);
            }
        }
    }
    ll sm=0;
    for(auto &it: st1)sm+=it;
    cout<<sm<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}