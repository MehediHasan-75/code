
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
    ll n, q;
    cin>>n>>q;
    set<ll>st;
    ll small=1;
    while(q--){
        ll a;
        cin>>a;
        if(a==1){
            st.insert(small++);
        }
        if(a==2){
           ll x;
           cin>>x;
           st.erase(x);
        }
        if(a==3){
            cout<<*st.begin()<<endl;
            // st.erase(st.begin());
        }
    }
}
int main()
{
    fastio;ll T = 1;
    //cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

