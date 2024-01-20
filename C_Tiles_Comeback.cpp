
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
    ll n, k;
    cin>>n>>k;
    map<ll,ll>mp;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
        mp[v[i]]++;
    }
    if(mp[v.front()]<k){
        cout<<"NO\n";
        return;
    }
    if(mp[v.front()]>=k and v.front()==v.back()){
        cout << "YES\n";
        return;
    }
    ll k_=k;
    for(ll  i=0; i<n; i++){
        if(v.front()==v[i])k_--;
        mp[v[i]]--;
        if(!k_)break;
    }
    if(mp[v.back()]>=k){
        cout<<"YES\n";
        return;
    }
    cout << "NO\n";
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

