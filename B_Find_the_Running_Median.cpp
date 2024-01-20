#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define pi acos(-1.0)
double eps = 1e-12;
#define precision(n) cout << setprecision(n) << fixed;
typedef long double ld;
template <typename T>
using order_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;;
//kthElement = *myTree.find_by_order(1), index(zero based) = myTree.order_of_key(8);
int main(){
    typedef long long ll;
    ll n;
    cin>>n;
    order_set<ll>st;

    for(ll i=1; i<=n; i++){
        ll a;
        cin>>a;
        st.insert(a);

        if(i%2){
            double num=*st.find_by_order(st.size()/2);
            precision(1);
            cout<<num<<endl;
        }
        else{
            precision(1);
            double num1=*st.find_by_order(st.size()/2), num2=*st.find_by_order((st.size()/2 )-1);
            cout<<(num1+num2)/2.0<<endl;
        }
    }
}