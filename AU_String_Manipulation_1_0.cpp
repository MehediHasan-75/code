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
    ll k;
    cin>>k;

    string s;
    cin>>s;

    ll r;
    cin>>r;

    string st="";
    while(k--)st+=s;

    vector<order_set<ll>>v(26);

    for(ll i=0; i<st.size(); i++){
        v[st[i]-'a'].insert(i);
    }

    while(r--){
        ll ind;
        char ch;
        cin>>ind>>ch;
        ind--;
        // cout<<ind<<" "<<ch<<endl;
        ll i= *v[ch-'a'].find_by_order(ind);
        // cout<<i<<endl;
        st[i]='#';
        v[ch-'a'].erase(i);
    }
    for(auto &it: st){
        if(it=='#')continue;
        cout<<it;
    }
}