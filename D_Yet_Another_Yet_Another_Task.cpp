#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin >> n;
    vector<ll>v;
    for(int i=0;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }
    ll ans=0, mx=0, mval=0;
    for(ll i=0; i<n; i++){
        mx=mx+v[i];
        cout<<mx<<" "<<ans<<endl;
        if(mx>0){
            mval=max(mval, v[i]);
            ans=max(ans, mx-mval);
        }
        else{
            ans=max(ans, mx-v[i]-mval);
            mval=0;
            mx=0;
        }
    }
    cout<<ans<<endl;
}