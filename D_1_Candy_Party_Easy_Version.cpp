#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n, sm=0;
    cin>>n;
    vector<ll>v(n);
    if(sm%n !=0){
        cout<<"No\n";
        return;
    }
    ll val=sm/n;
    vector<ll>bits(35, 0);

    for(ll i=0; i<n; i++){
        ll temp=abs(val-v[i]), num=temp;
        ll cnt1=0, total=0;
        while(temp){
            if(temp&1)cnt1++;
            temp/=2;
            total++;
        }
        ll chk=0;
        for(ll j=total-cnt1; j<total; j++){
            chk|=(1<<j);
        }
        // cout<<chk<<endl;
        if(chk!=num){
            cout<<"No\n";
            return;
        }
        ll x=total+1, y=total-cnt1+1;
        if(val>v[i])bits[x]++, bits[y]--;
        else bits[x]--, bits[y]++;
        // cout<<x<<" "<<y<<endl;
    }
    for(ll i=0; i<35; i++){
        // cout<<i<<" "<<bits[i]<<endl;
        if(bits[i]!=0){
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
}
int main(){
    ll t;
    cin>>t;
    while(t--)solve();
}