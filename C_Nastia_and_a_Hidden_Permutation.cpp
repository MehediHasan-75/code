#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll query(ll t, ll i, ll j, ll x){
    cout<<"? "<<t<<" "<<i<<" "<<j<<" "<<x<<"\n";
    cout.flush();
    ll val;
    cin>>val;
    return val;

}

ll findN(ll n){
    for(ll i=1;i<n;i+=2){
      ll ret=query(1,i,i+1,n-1);
      if(ret==n){
        return i+1;
      }
      else if(ret==n-1){

        ll ret=query(1,i+1,i,n-1);
        if(ret==n){
          return i;
        }
      }
    }
    return n;
}

void solve(){
    ll n;
    cin>>n;
    ll arr[n+1];
    ll in=findN(n);
    
    arr[in]=n;
    for(ll i=1;i<=n;i++){
        if(i!=in){
          arr[i]=query(2,i,in,1);
        }
    }
    cout<<"! ";
    for(ll i=1;i<=n;i++){
      cout<<arr[i]<<" ";
    }
    cout<<"\n";
    cout.flush();
}
int main(){
      ios_base::sync_with_stdio(0);
      ll t;
      cin>>t;
      while(t--)solve();
}