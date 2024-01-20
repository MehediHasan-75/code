
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
ll primefactor(ll n)
{
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
                return i;
            }
        }
    }
    return -1;
}
void solve(ll tc)
{
   ll l, r;
   cin>>l>>r;
  for(ll i=l; i<=r; i++){
     ll x=primefactor(i);
    //  cout<<i<<" "<<x<<endl;
     if(x!=-1){
        ll num=i/x;
        cout<<num<<" "<<(x-1)*num<<endl;
        return;
     }
  }  
  cout<<-1<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

