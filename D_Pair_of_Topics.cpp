
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
namespace __gnu_pbds{
          typedef tree<long long,
                       null_type,
                       less_equal<long long>,
                       rb_tree_tag,
                       tree_order_statistics_node_update> ordered_set;
}
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<ll> vll;
const ll N = 2e5 + 10, inf=2e18;
ll mod = 1000000007;
void solve(ll tc)
{
  ll n;
  cin>>n;
  vector<ll>v(n);
  for(ll i=0; i<n; i++){
    cin>>v[i];
  }
  vector<ll>vv(n);
  for(ll i=0; i<n; i++){
    cin>>vv[i];
  }
  ll cnt=0;
  ordered_set st;
  for(ll i=0; i<n; i++){
    ll dif=vv[i]-v[i];
    ll x=st.order_of_key(dif+1);
    cnt+=st.size()-x;
    st.insert(-dif);
  }
  // for(ll i=0; i<n; i++){
  //   for(ll j=i+1; j<n; j++){
      
  //     //if(v[i]+v[j]>vv[i]+vv[j])
  //     if(v[i]-vv[i]>vv[j]-v[j]){
  //       cout<<v[i]<<" "<<v[j]<<endl;
  //       cout<<vv[i]<<" "<<vv[j]<<endl;
  //     }
  //   }
  // }
  cout<<cnt<<endl;
}
int main()
{
    fastio;ll T = 1;
    //cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

