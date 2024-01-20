#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, k;
    cin>>n>>k;

    vector<string>v(n);
    for(ll i=0; i<n; i++)cin>>v[i];

    vector<ll>p, p_;
    for(ll i=0; i<k; i++)p.push_back(i);
    p_=p;

    vector<vector<ll>>per;
    do{
        per.push_back(p);
        next_permutation(p.begin(), p.end());
    }while(p!=p_);
    ll ans=INT64_MAX;

    for(auto &it: per){
        ll mx=-1, mi=INT64_MAX;
        for(ll i=0; i<n; i++){
            ll num=0;

            for(auto &ind: it){
                num=num*10+(v[i][ind]-'0');
            }
            mx=max(mx, num), mi=min(mi, num);
        }
        ans=min(ans, mx-mi);
    }
    cout<<ans<<endl;
}