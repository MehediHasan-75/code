#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, q;
    cin>>n>>q;

    for(ll i=1; i<n; i++)cout<<i<<" "<<i+1<<endl;

    ll dist=n-1;


    while(q--){
        ll x;
        cin>>x;

        if(dist==x){
            cout<<"-1 -1 -1\n";
        }
        else{
            cout<<n<<" "<<dist<<" "<<x<<endl;
            dist=x;
        }
    }
}
int main(){
    ll t;
    cin>>t;

    while(t--)solve();
}