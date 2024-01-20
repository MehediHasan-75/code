#include<bits/stdc++.h>
#define ll long long
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
template <typename T>
using order_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;;
//kthElement = *myTree.find_by_order(1), index(zero based) = myTree.order_of_key(8);
bool cmp(pair<pair<ll,ll>, ll>& p1, pair<pair<ll, ll>, ll> &p2){
    if(p1.first.second!=p2.first.second){
        return p1.first.second<p2.first.second;
    }
    return p1.first.first> p2.first.first;
}
int main(){
    ll n;
    cin>>n;
    vector<pair<pair<ll,ll>, ll>>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i].first.first>>v[i].first.second;
        v[i].second=i;
    }
    sort(v.begin(), v.end(), cmp);
    order_multiset<ll> st;
    vector<ll>ans(n);
    for(ll i=0; i<n; i++){
        ll l=v[i].first.first, r=v[i].first.second, ind=v[i].second;
        st.insert(l);
        ans[ind]=st.size() - st.order_of_key(l+1);
    }
    for(auto &it: ans)cout<<it<<endl;
}