#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 200000
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll anyp[N];
vector<ll>pos[N];
bool ok(ll left, ll right){
    for(ll i=0; i<pos[left].size(); i++){
        if(pos[left][i]+1!=pos[right][i])return 0;
    }
    return 1;
}
int main(){
    ll n, m;
    fastio;
    cin>>n>>m;
    while(m--){
        for(ll i=1; i<=n; i++)cin>>anyp[i], pos[anyp[i]].push_back(i);
    }
    ll ans=0, k=1;
    for(ll i=2; i<=n; i++){
        if(ok(anyp[i-1], anyp[i])) k++;
        else ans+=(k*(k+1))/2, k=1;
    }
    ans+=(k*(k+1))/2;
    cout<<ans<<endl;
}