#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll func(ll left, ll right, vector<ll>&v){
    // cout<<v[left]<<" "<<v[right]<<" "<<v.size()<<" "<<left<<" "<<right<<endl;
    if(v[left]*2>=v[right])return v.size()-(right-left+1);

    return min(func(left+1, right, v), func(left, right-1, v));
}
int main(){
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;


    vector<ll>v(n);
    for(auto &it: v)cin>>it;

    sort(v.begin(), v.end());

    cout<<func(0, n-1, v)<<endl;
}