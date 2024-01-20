
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
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T>
using order_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
void solve(ll tc)
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll>b(m);
    order_set<ll>st;
    for(auto &it: a){
        cin>>it;
        st.insert(it);
    }
    for(auto &it: b){
        cin>>it;
        st.insert(it);
    }
    for(auto &it: a){
        cout<<st.order_of_key(it)+1<<" ";
    }
    cout<<"\n";
    for(auto &it: b){
        cout<<st.order_of_key(it)+1<<" ";
    }
    cout<<"\n";
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

