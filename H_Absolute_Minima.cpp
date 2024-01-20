#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
template <typename T>
using order_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;;
//kthElement = *myTree.find_by_order(1), index(zero based) = myTree.order_of_key(8);
multiset<ll>st1, st2;
ll sm1, sm2, sm3;
void balance(){
    if(st1.size()>st2.size()+1){
        auto it=st1.end();
        it--;
        sm1-=*it;
        sm2+=*it;
        st1.erase(it);
        st2.insert(*it);
    }
    if(st1.size()<st2.size()){
        auto it=st2.begin();
        sm2-=*it;
        sm1+=*it;

        st2.erase(it);
        st1.insert(*it);
    }
    return;
}
void add(ll x, ll y){
    sm3+=y;

    if(st1.empty() or x<=(*st1.rbegin())){
        st1.insert(x);
        sm1+=x;
    }
    else{
        st2.insert(x);
        sm2+=x;
    }
    balance();
}
void get(){
    ll x=*st1.rbegin();
    ll y= x*st1.size()- sm1 + sm2 - st2.size()*x+sm3;
    cout<<x<<" "<<y<<"\n"; 
}
int main(){
    ll n;
    cin>>n;
    ll sm=0;
    for(ll i=0; i<n; i++){
        ll type, x, y;
        cin>>type;
        if(type==1){
            cin>>x>>y;
            add(x, y);
        }
        else get();
    }
}