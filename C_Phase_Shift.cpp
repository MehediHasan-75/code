
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 2e5 + 10, inf=2e18;
ll mod = 1000000007, parent[26];
ll find_parent(ll u){
    if(parent[u]==u)return u;
    return parent[u]=find_parent(parent[u]);
}
void unin(ll u, ll v){
    ll pu=parent[u], pv=parent[v];
    parent[pu]=pv;
}
void solve(ll tc)
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    map<ll,ll>mp;
    set<ll>st;
    for(ll i=0; i<26; i++)parent[i]=i, st.insert(i);
    for(ll i=0; i<n; i++){
        ll ch=s[i]-'a';
        if(mp.count(ch))continue;
        if(mp.size()==25){
            mp[ch]= *st.begin();
            st.erase(st.begin());
        }
        else{
            for(auto &it: st){
                if(find_parent(it)!=find_parent(ch)){
                    mp[ch]=it;
                    unin(it, ch);
                    st.erase(it);
                    break;
                }
            }
        }
    }
    // unin(1, 2);
    // cout<<find_parent(1)<<endl;

    for(ll i=0; i<n; i++){
        cout<<char(mp[s[i]-'a']+'a');
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

