
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
template <typename T>
using order_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;;
//kthElement = *myTree.find_by_order(1), index(zero based) = myTree.order_of_key(8);

typedef long long ll;
typedef vector<ll> vll;
const ll N = 2e5 + 10, inf=2e18;
ll mod = 1000000007;
void solve(ll tc)
{
    ll n, k;
    cin>>n>>k;
    vector<ll>v(n), mrk(k+1, 0);
    for(auto &it: v)cin>>it, mrk[it]++;

    vector<ll>first(k+1, -1), last(k+1, -1);
    set<ll>st;
    for(ll i=1; i<=k; i++)st.insert(i);


    for(ll i=n-1; i>=0; i--){
        while(st.size() and *(st.begin())<= v[i]){
            ll col= *st.begin();
            last[col]=i;
            st.erase(st.begin());
        }
        if(st.size()==0)break;
    }
    // for(ll i=1; i<=k; i++)cout<<last[i]<<" ";
    // cout<<endl;
    set<ll>st1;
    for(ll i=1; i<=k; i++)st1.insert(i);

    for(ll i=0; i<n; i++){
        if(first[v[i]]!=-1)continue;
        while(st1.size() and *(st1.begin())<= v[i]){
            ll col= *st1.begin();
            first[col]=i;
            st1.erase(st1.begin());
        }
        if(st1.size()==0)break;
    }

    for(ll i=1; i<=k; i++){
        if(mrk[i]==0){
            cout<<0<<" ";
            continue;
        }
        cout<<2*(last[i]-first[i]+1)<<" ";
    }
    // for(ll i=1; i<=k; i++)cout<<ans[i]<<" ";
    cout<<endl;
}   
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

