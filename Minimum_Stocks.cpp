
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
    map<string, ll>mp;
    set<pair<ll,string>>st;
    for(ll i=1; i<=n; i++){
        ll t;
        cin>>t;

        if(t==1){
            string s;
            cin>>s;
            ll price;
            cin>>price;

            mp[s]=price;
            st.insert({price, s});
        }
        else if(t==2){
            string s;
            cin>>s;

            ll price;
            cin>>price;
            st.erase({mp[s], s});
            mp[s]=price;
            st.insert({price, s});
        }
        else{
            string s;
            cin>>s;
            cout<< (*st.begin()).second<<" "<<i<<endl;
            st.erase(st.begin());
        }
    }
}
int main()
{
    fastio;ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

