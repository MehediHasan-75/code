#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;

    vector<ll>v(n);
    for(auto &it: v)cin>>it;
    // for(ll i=0; i<n; i++)cout<<v[i]<<" ";
    // cout<<endl;

    vector<ll>divisors;
    for(ll i=1; i*i<=n; i++){
        if(i*i==n){
            divisors.push_back(i);
        }
        else if(n%i==0){
            divisors.push_back(i);
            divisors.push_back(n/i);
        }
    }
    ll ans=0;
    for(auto &k: divisors){
        // cout<<k<<" ";
        ll gc=0, part=n/k;

        for(ll i=0; i<k; i++){
            ll temp_gc=0;
            for(ll j=i; j<n; j+=k){
                temp_gc=__gcd(temp_gc, abs(v[i]-v[j]));
            }
            gc=__gcd(temp_gc, gc);
        }
        if(gc!=1)ans++;
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    while(t--)solve();
}