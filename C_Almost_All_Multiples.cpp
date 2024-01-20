#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
  ll n, x;
  cin>>n>>x;
  if(n%x){
    cout<<-1<<endl;
    return;
  }
  vector<ll>v(n+1, 0);
  v[1]=x, v[n]=1;

  ll num=n/x;
  vector<ll>divi;
  for(ll i=2; i*i<=num ; i++){
    while(num%i==0){
        divi.push_back(i);
        num/=i;
    }
  }
  if(num>1)divi.push_back(num);
//   for(auto &it: divi)cout<<it<<" ";
  ll ind=x;
  for(auto &it: divi){
    v[ind]=it*ind;
    ind=it*ind;
  }
  for(ll i=1; i<=n; i++)cout<<(v[i]==0? i: v[i])<<" ";
  cout<<endl;
}
int main(){
    ll t;
    cin>>t;
    while(t--)solve();
}