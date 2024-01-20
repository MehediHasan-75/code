
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
   string s[3];
    for(ll i=0; i<3; i++)cin>>s[i];
    ll x, y;
   map<char, ll>mp;
   for(ll i=0; i<3; i++){
    for(ll j=0; j<3; j++){
        if(s[i][j]=='?'){
            for(auto &it: s[i]){
                mp[it]++;
            }
            for(ll k=0; k<3; k++){
                mp[s[k][j]]++;
            }
        }
    }
   }

    if(!mp['A'])cout<<"A\n";
    else if(!mp['B'])cout<<"B\n";
    else cout<<"C\n";
   
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

