#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll a, b, c, d;
    cin>>a>>b>>c>>d;
    ll mx=b+d, mi=a+c, ans=0;

    if(mx-mi+1>=10){
        ans=9;
    }
    else{
        for(ll num=mi; num<=mx; num++){
            ll x=num;
            while(x){
                ans=max(x%10, ans);
                x/=10;
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    ll t;
    cin>>t;
    while(t--)solve();
}