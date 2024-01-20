#include<bits/stdc++.h>
using namespace std;
int main(){
    typedef long long ll;
    ll n;
    cin>>n;
    vector<ll>a(n), b(n, 0);

    for(ll i=1; i<n; i++)cin>>a[i];

    // we have to chose only b[0] rest of the values are fixed becaues b[i]=a[i]^b[i-1];
    for(ll bit=0; bit<31; bit++){
        // we can take each bit in b[0] as 1 or 0.

        ll cntze=1, xo=0;

        for(ll i=1; i<n; i++){
            xo^=(a[i]&(1<<bit));
            if(!xo)cntze++;
        }
        if(cntze>=(n+1)/2){
            xo=0;

            for(ll i=1; i<n; i++){
                xo^=((a[i]&(1<<bit)));
                if(xo)b[i]+=(1<<bit);
            }
        }
        else{
            xo=(1<<bit);
            b[0]+=(1<<bit);

            for(ll i=1; i<n; i++){
                xo^=((a[i]&(1<<bit)));
                if(xo)b[i]+=(1<<bit);
            }
        }
    }
    for(auto &it: b)cout<<it<<" ";
    cout<<endl;
}