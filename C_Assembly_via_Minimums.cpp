
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
    ll n, mx=INT64_MIN;
    cin>>n;
    set<ll>st;
    map<ll,ll>mp;
    for(ll i=0; i<n*(n-1)/2; i++){
        ll a;
        cin>>a;
        mp[a]++;
        st.insert(a);
    }
    cout<<(mp.rbegin())->first<<" ";
    ll sz=n-1;
    while(!mp.empty()){
        auto it=mp.begin();
        ll u=it->first;
        cout<<u<<" ";
        // assert(mp[u]>=sz);
        mp[u]-=sz;
        //cout<<mp[u]<<endl;
        if(mp[u]==0)mp.erase(u);
        sz--;
        //if(sz==0)break;
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

