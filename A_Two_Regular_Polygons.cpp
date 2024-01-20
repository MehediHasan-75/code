#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n, m;
    cin>>n>>m;
    cout<< (n%m==0 ? "YES\n":"NO\n");
}
int main(){
    ll t;
    cin>>t;
    while(t--)solve();
}