#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
ll phi[1000005];
void calc(){
    for(ll i=0; i<N; i++)phi[i]=i;
    for(ll i=2; i<N; i++){
        if(phi[i]==i){
            for(ll j=i; j<N; j+=i){
                phi[j]-=phi[j]/i;
            }
        }
    }
}
void solve(){
    ll n;
    cin>>n;
    cout<<phi[n]<<endl;
}
int main(){
    ll t;
    cin>>t;
    calc();
    while(t--)solve();
}