
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
   ll n, m;
   cin>>n>>m;

   vector<vector<ll>>v(n);
   for(ll i=0; i<n; i++){
        vector<ll>temp(m);
        for(auto &it: temp)cin>>it;

        v[i]=temp;
   }
   vector<ll>col(n);
   for(ll i=0; i<m; i++){
        for(auto &it: col)cin>>it;
   }
//    prnt(col);
   pair<ll,ll>p;
   for(ll i=0; i<n; i++){
    for(ll j=0; j<m; j++){
        for(ll k=0; k<n; k++){
            if(col[k]==v[i][j]){
                p={i, j};
                break;
            }
        }
    }
   }
//    cout<<p.first<<" "<<p.second<<endl;

   vector<pair<ll,vector<ll>>>ans;
    ll cl=p.second;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            if(col[j]==v[i][cl]){
                ans.push_back({j, v[i]});
                break;
            }
        }
    }
    sort(ans.begin(),ans.end());
    for(auto &it: ans){
        prnt(it.second)
    }
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

