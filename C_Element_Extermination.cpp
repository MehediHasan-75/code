
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
    stack<ll>st;
    for(ll i=n-1; i>=0; i--){
        if(!st.size()){
            st.push(v[i]);
            continue;
        }
        if(st.size()>1){
            while(st.size()>1 and v[i]<st.top()){
                st.pop();
            }
        }
        if(st.top()<v[i]){
            st.push(v[i]);
        }
    }
    if(st.size()==1)cout << "YES\n";
    else cout << "NO\n";
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

