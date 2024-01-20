#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    typedef long long ll;
    ll n, b;
    cin>>n>>b;

    vector<ll>vv;

    for(ll i=0; i<n; i++){
        ll x, y, t, v;
        cin>>x>>y>>t>>v;
        if(y>x and y-x>t and y<=t*b){
            vv.push_back(v);
        }
    }
    sort(vv.begin(), vv.end(), greater<ll>());

    ll profit=0,ans=0;
    for(ll i=0; i<vv.size(); i++){
        if(vv[i]*(i+1)>=profit){
            ans=vv[i];
            profit=vv[i]*(i+1);
        }
    }
    cout<<ans<<endl;
}