
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
    vector<ll>v(n);
    for(auto &it: v)cin>>it;
    set<ll>st, win;
    st.insert(v[0]);
    for(ll i=1; i<n; i++){
        ll x=v[i];
        if(*st.begin()<x){
            if(!win.size())win.insert(x);
            else if(*win.begin()>x)win.insert(x);
        }
        st.insert(x);
    }
    cout<<win.size()<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

