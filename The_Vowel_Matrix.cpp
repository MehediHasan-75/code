
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
bool is_vow(char ch){
    return ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u';
}
void solve(ll tc)
{
    ll n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll ans=1;
    vector<ll>v;
    for(ll i=0; i<n; i++){
        if(is_vow(s[i]))v.push_back(i);
    }
    ll cnt=0;
    for(ll i=0; i<v.size(); i++){
        cnt++;
        if(cnt==k and i+1<v.size()){
            ans=(ans*(v[i+1]-v[i]))%mod;
            cnt=0;
        }
    }
    cout<<ans<<endl;
    
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

