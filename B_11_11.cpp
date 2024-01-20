#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool func(ll num, ll dit){
    set<ll>st;
    // st.insert(dit);
    // cout<<num<<" "<<dit<<endl;
    while(num){
        st.insert(num%10);
        num/=10;
    }
    while(dit){
        st.insert(dit%10);
        dit/=10;
    }
    // cout<<st.size()<<endl; 
    return st.size()==1;
}
int main(){
    ll n;
    cin>>n;
    ll cnt=0;
    for(ll i=1; i<=n; i++){
        ll a;
        cin>>a;
        // cout<<a<<endl;
        ll cn=0;
        for(ll j=1; j<=a; j++){
            if(func(j, i))cnt++, cn++;
        }
        // cout<<i<<" "<<cn<<endl;
   }
    cout<<cnt<<endl;

}