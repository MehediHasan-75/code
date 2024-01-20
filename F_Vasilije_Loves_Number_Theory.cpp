#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll>mp;
ll addHobe(ll n){
    ll  divkoto=1;
    for(ll i=2; i*i<=n; i++){
        ll j=0;
        while(n%i==0) n/=i, j++;
        if(j)mp[i]+=j;
    }
    if(n>1)mp[n]++;
    for(auto &it: mp)divkoto*=(it.second+1);
    return divkoto;
}
void solve(){
    mp.clear();
    ll n, q;
    cin>>n>>q;
    addHobe(n);
    map<ll,ll>mp1=mp;
    while(q--){
        ll id;
        cin>>id;
        if(id==2){
            mp=mp1;
        }
        else{
            ll x;
            cin>>x;
            ll divi_n=addHobe(x);
            // cout<<divi_n<<endl;
            auto chk=[&](ll &val, ll prime, ll cnt){
                while(cnt>0 and val%prime==0){
                    cnt--;
                    val/=prime;
                }
            };
            for(auto &it: mp){
                chk(divi_n, it.first, it.second);
            }
            cout<<((divi_n==1)? "YES\n":"NO\n");
        }
    }cout<<"\n";
}
int main(){
    ll t;
    cin>>t;
    while(t--)solve();
}