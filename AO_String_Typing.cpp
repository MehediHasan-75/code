#include<bits/stdc++.h>
using namespace std;
int main(){
    typedef long long ll;
    ll n;
    cin>>n;

    string s;
    cin>>s;

    ll ans=n, mx=1;

    for(ll i=1; i*2<=n; i++){
        if(s.substr(0, i)==s.substr(i, i)){
            mx=max(mx, i);
        }
    }
    cout<<ans-(mx-1)<<endl;
}