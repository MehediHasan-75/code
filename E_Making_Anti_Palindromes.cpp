
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
    string s;
    cin>>s;
    if(n&1){
        cout<<-1<<endl;
        return;
    }
    vector<ll>cnt(27, 0);
    for(auto &it: s)cnt[it-'a']++;
    for(ll i=0; i<27; i++){
        if(cnt[i]>n/2){
            cout<<-1<<endl;
            return;
        }
    }
    vector<ll>cntt(27, 0);
    for(ll i=0; i<n/2; i++){
        if(s[i]==s[n-i-1]){
            cntt[s[i]-'a']++;
            // cout<<cntt[i]<<" ";
        }
    }
    multiset<ll>st;
    for(ll i=0; i<27; i++){
        if(cntt[i])st.insert(cntt[i]);
    }
    ll ans=0;
    while(st.size()>1){
        ll x= *st.begin(), y=*st.rbegin();
        st.erase(st.begin()), st.erase( --st.end());
        ans++;
        x--;
        y--;
        if(y){
            st.insert(y);
        }
        if(x){
            st.insert(x);
        }
    }
    if(st.size())ans+=(*st.begin());
    cout<<ans<<endl;
    
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

