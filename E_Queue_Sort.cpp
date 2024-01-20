
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

  vector<ll>v(n);

  ll mi=INT64_MAX, in=-1;

  for(ll i=0; i<n; i++){
    cin>>v[i];

    if(v[i]<mi){
        mi=v[i];
        in=i;
    }
  }
//   cout<<mi<<" "<<in<<endl;
  bool fl=1;
  for(ll i=in+1; i<n; i++){
    if(v[i]<v[i-1]){
        fl=0;
        break;
    }
  }
  if(!fl)cout<<-1<<endl;
  else cout<<in<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

