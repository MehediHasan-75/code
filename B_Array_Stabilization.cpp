#include<bits/stdc++.h>
using namespace std;
int main(){
    typedef long long ll;
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    if(v.size()==2)cout<<0<<endl;
    else cout<<min(v[n-2]-v[0], v[n-1]-v[1])<<endl;
}