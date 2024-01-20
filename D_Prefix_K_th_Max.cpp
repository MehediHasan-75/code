#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
template <typename T>
using order_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::greater_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;;
//kthElement = *myTree.find_by_order(1), index(zero based) = myTree.order_of_key(8);
int main(){
    ll n, k;
    cin>>n>>k;
    // cout<<k<<endl;
    order_multiset<ll>st;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    for(ll i=0; i<k-1; i++){
        st.insert(v[i]);
    }
    // ll cnt=0;
    for(ll i=k-1; i<n; i++){
        st.insert(v[i]);
        // cout<<st.size()<<endl;
        cout<<*st.find_by_order(k-1)<<" ";
    }
    // for(auto &it: st)cout<<it<<" ";
}