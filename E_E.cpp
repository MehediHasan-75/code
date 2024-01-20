
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
using order_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;;
//kthElement = *myTree.find_by_order(1), index(zero based) = myTree.order_of_key(8);

void solve(ll tc)
{
    ll n;
    cin>>n;
    
    // pos[v[i]=4]=5, curpos=i;
    //total=pos[4]-curpos - koyta bad.--->>koyta bad=st.find_byorder(curpos).

    vector<ll>v(n), pos(n);

    for(ll i=0; i<n; i++){
        cin>>v[i];
        v[i]--;
    }
    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        a--;
        pos[a]=i;
    }
    order_set<ll>st;

    ll cnt=0;
    for(ll i=0;i<n; i++){
        ll posa=i, posb=pos[v[i]];

        st.insert(posb);
        ll rem=st.order_of_key(posb);
        // cout<<i<<" ";
        // cout<<posb-rem<<endl;
        cnt+=posb-rem;
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

