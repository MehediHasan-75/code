
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
template <typename T>
using order_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
//kthElement = *myTree.find_by_order(1), index(zero based) = myTree.order_of_key(8);
void solve(ll tc)
{
    ll n;
    cin>>n;
    ll cnt=0;
    order_multiset<ll>st;
    for(ll i=0; i<n; i++){
      ll a;
      cin>>a;
    //   cout<<a<<" ";
      st.insert(a);
      ll ind1=st.order_of_key(a), ind2=st.order_of_key(a+1);
      cnt+=min(ind1, (ll)st.size()-ind2);
    }
    cout<<cnt<<" "<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

