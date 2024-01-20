
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 2e5 + 10, inf=2e18;
ll mod = 1000000007;
void solve(ll tc)
{
    ll n;
    cin>>n;
    vector<ll>v1(n), v2(n);
    map<ll,ll>mp1, mp2;
    for(auto &it: v1){
        cin>>it;
    }
    for(auto &it: v2){
        cin>>it;
    }
    for(ll i=0; i<n; i++){
        ll cnt=1, num=v1[i];
        while(i+1<n and v1[i]==v1[i+1])i++, cnt++;
        mp1[num]=max(mp1[num], cnt);
    }
    for(ll i=0; i<n; i++){
        ll cnt=1, num=v2[i];
        while(i+1<n and v2[i]==v2[i+1])i++, cnt++;
        mp2[num]=max(mp2[num], cnt);
    }
    ll mx=0;
    for(auto &it: mp1){
        mx=max(mx, it.second+mp2[it.first]);
    }
    for(auto &it: mp2){
        mx=max(mx, it.second+mp1[it.first]);
    }
    cout<<mx<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

