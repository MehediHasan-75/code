#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll x, y, q;
    cin>>x>>y>>q;
    ll leftx=0, rightx=x, upy=y, downy=0;
    while(q--){
        ll x_, y_, a;
        cin>>x_>>y_>>a;
        if(a==1){
            leftx=max(leftx, x_);
        }
        else if(a==2){
            rightx=min(rightx, x_);
        }
        else if(a==3){
            downy=max(y_, downy);
        }
        else{
            upy=min(y_, upy);
        }
    }
    //cout<<leftx<<" "<<rightx<<" "<<upy<<" "<<downy<<endl;
    if((upy-downy)<=0 or (rightx- leftx)<=0)cout<<0<<endl;
    else cout<<(upy-downy)*(rightx- leftx)<<'\n';
}