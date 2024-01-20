#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
template <typename T>
using order_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;;
//kthElement = *myTree.find_by_order(1), index(zero based) = myTree.order_of_key(8);
int main(){
    typedef long long ll;
    ll n, a, b;
    cin>>n>>a>>b;

    order_set<ll>stall, stb;
    string s;
    cin>>s;

    for(ll i=0; i<s.size(); i++){
        if(s[i]=='a'){
            if(stall.size()<a+b){
                cout<<"Yes\n";
                stall.insert(i);
            }
            else cout<<"No\n";
        }
        else if(s[i]=='b'){
            if(stall.size()< a+b and stb.size()<b){
                cout<<"Yes\n";
                stall.insert(i);
                stb.insert(i);
            }
            else cout<<"No\n";
        }
        else cout<<"No\n";
    }
    
}