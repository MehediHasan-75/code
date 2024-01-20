#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll calc(ll x, ll y){
    ll ans=1, r=x, n=x+y;
    for(ll i=0; i<r; i++){
        ans*=(n-i);
        ans/=(i+1);
    }
    return ans;
}
void func(ll left, ll right, ll need){
    if(left==0 and right==0)return;
    ll cnt_left=0, cnt_right=0;
    if(left>0)cnt_left=calc(left-1, right);
    if(right>0)cnt_right=calc(left, right-1);
    if(need<=cnt_left){
        s.push_back('a');
        func(left-1, right, need);
    }
    else{
        s.push_back('b');
        func(left, right-1, need-cnt_left);
    }
}
int main(){
    ll a, b, k;
    cin>>a>>b>>k;
    func(a, b, k);
    cout<<s<<endl;
    //cout<<calc(2, 2)<<endl;
}