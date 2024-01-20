
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
vector<ll>v(N);
// states ind con

void solve(ll tc)
{
    //cout<<"Case "<<tc<<": ";
    ll n;
    cin>>n;
    //cout<<n<<endl;
    vector<ll>v;
    ll prev=-1;
    for(ll i=0; i<n; i++){
      ll a;
      cin>>a;
      //cout<<a<<" ";
      if(prev!=a)v.push_back(a), prev=a;
    }
    vector<ll>ans;
   // prnt(v);
    ll cnt=v.size();
    //ans.push_back(v[0]);
    for(ll i=1; i<v.size()-1; i++){
        if(v[i]>v[i-1] and v[i]<v[i+1])cnt--;
        else if(v[i]<v[i-1] and v[i]>v[i+1])cnt--;
    }
    //cout<<endl;
    cout<<cnt<<endl;
    //prnt(ans);
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

