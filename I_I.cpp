#include<bits/stdc++.h>
using namespace std;
int main(){
    typedef long long ll;
    ll a, b;
    cin>>a>>b;
    ll x=min(a, b);
    cin>>a>>b;
    ll y=min(a, b);

    if(x==y)cout<<"Tie\n";
    else if(x>y){
        cout<<"Alice\n";
    }
    else cout<<"Bob\n";
}