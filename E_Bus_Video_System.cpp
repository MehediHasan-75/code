#include<bits/stdc++.h>
using namespace std;
int main(){
    typedef long long ll;
    ll n, w;
    cin>>n>>w;

    //lets start with Npassenger = 0.
    // x0 a1 x1 a2 x2 a3 x3 here a1, a2, a3 are constants. Xi+1 (new N passenger after each st) = Xi + ai
    ll mx=0, mi=0, x=0;

    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        x+=a;

        if(x>0)mx=max(mx, x);
        if(x<0)mi=max(mi, -x);
    }
    cout<<max(0ll,(w-mx)-mi+1)<<endl;
}