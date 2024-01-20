
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
    // cout<<tc<<endl;
    set<ll>st;
    map<ll,ll>mp;
    for(ll i=0; i<3; i++){
        ll a;
        cin>>a;
        st.insert(a);
        mp[a]++;
    }
    ll cnt=0;
    while(st.size()!=1){
        ll mi=*st.begin(), mx=*st.rbegin();
        st.erase(mx);

        if((mx%mi))st.insert(mx%mi), mp[(mx%mi)]++;
        mp[mi]+=mx/mi;
        cnt+= ( ( (mx+mi-1)/ mi ) -1 )* mp[mx];
        if(cnt>3){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

