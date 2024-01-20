#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll grandy(ll n){
    if(n==1)return 0;
    if(n==2) return 1;
    vector<ll>v;
    for(ll i=1; i<=n/2; i++){
        v.push_back(grandy(n-i));
    }
    sort(v.begin(), v.end());
    cout<<"n = "<<n<<endl;
    for(auto &it: v)cout<<it<<"  ";
    cout<<endl;
    ll mx=0;
    for(ll i=0; i<v.size(); i++){
        if(v[i]==mx)mx++;
    }
    return mx;
}
int main(){
   cout<<grandy(5)<<endl; 
}