
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
template <typename T>
using order_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;;
//kthElement = *myTree.find_by_order(1), index(zero based) = myTree.order_of_key(8);
typedef long long ll;
typedef vector<ll> vll;
const ll N = 2e5 + 10, inf=2e18;
ll mod = 1000000007;
void solve(ll tc)
{
    ll m, n;
    cin>>m>>n;
    order_multiset<ll>st;
    ll cnt=0;
    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        st.insert(a);
        cnt+=st.order_of_key(a);
        // cout<<st.order_of_key(a)<<" ";
    }
    cout<<cnt<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

