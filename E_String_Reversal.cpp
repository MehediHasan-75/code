#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
template <typename T>
using order_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;;
//kthElement = *myTree.find_by_order(1), index(zero based) = myTree.order_of_key(8);
int main(){
    ios_base::sync_with_stdio(false);
    typedef long long ll;
    ll n;
    cin>>n;

    string s;
    cin>>s;
    vector<queue<ll>>v(26);


    for(ll i=0; i<n; i++){
        v[s[i]-'a'].push(i);
    }

    ll ans=0;

    reverse (s.begin(), s.end());
    order_set<ll>st;
    for(ll i=0; i<n; i++){
        ll now=s[i]-'a';
        // cout<<now<<" ";
        st.insert(v[now].front());
        ll saved=st.order_of_key(v[now].front());

        ans+=v[now].front()-saved;
        v[now].pop();
    }
    cout<<ans<<"\n";
}