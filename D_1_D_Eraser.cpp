
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
    vector<ll>v;
    string s;
    cin>>s;
    for(ll i=0; i<n; i++){
        if(s[i]=='B')v.push_back(i);
    }
    if(v.size()==0){
        cout<<0<<endl;
        return;
    }
    ll cnt=1, l=v.front();
    for(ll i=1; i<v.size(); i++){
        if(v[i]-l+1 >k)l =v[i], cnt++;
    }
    cout<<cnt<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

