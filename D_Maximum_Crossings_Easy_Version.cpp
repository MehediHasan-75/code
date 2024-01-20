
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

ll chk(ll x, ll y, ll x1, ll y1){
    if((x<x1 and y<y1) or (x>x1 and y>y1))return 0;
    return 1;
}
void solve(ll tc)
{
   ll n;
   cin>>n;

   vector<ll>v(n);

   for(auto &it: v)cin>>it, it--;

//    prnt(v);
   ll cnt=0;

   for(ll i=0; i<n; i++){
    for(ll j=0; j<n; j++){
        if(i==j )continue;

        if(chk(i, v[i], j, v[j]))cnt++;
    }
   }
   cout<<cnt/2<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

