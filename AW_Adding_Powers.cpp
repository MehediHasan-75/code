
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
    // cout<<n<<" "<<k<<endl;
   map<ll,ll>mp;
   bool fl=0;
   for(ll i=0; i<n; i++){
        ll a, cnt=0;
        cin>>a;
        // cout<<endl<<a<<" : ";
        while(a){
           ll r=a%k;
           if(r>1){
            fl=1;
           }
           if(r==1)mp[cnt]++;
           cnt++;
        //    cout<<r<<" "<<cnt-1<<" ";
           a/=k;
        }
        // cout<<endl;
   }
//    cout<<endl;
   if(fl){
    cout << "NO\n";
    return;
   }
   for(auto &it: mp){
    if(it.second>1){
        cout << "NO\n";
        return;
    }
   }
   cout << "YES\n";
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

