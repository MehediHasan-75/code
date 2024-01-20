#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll func(vector<ll>&v){
    ll n=v.size();
    sort(v.begin(), v.end());

    return v[(n)/2]-v[(n-1)/2]+1;
}
void solve(){
    ll n;
    cin>>n;

    vector<ll>x(n), y(n);

    for(ll i=0; i<n; i++)cin>>x[i]>>y[i];

    cout<<func(x)*func(y)<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    while(t--)solve();
}