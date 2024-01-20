
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
ll row, col, cnt=0;
ll s[1005][1005];
bool is_valid(ll r, ll c)
{
    if(r<0 or c<0 or r>=row or c>=col or s[r][c]==0 )return false;// s[r][c]='.' means desired element in matrix.
    return true;
}
vector<pair<ll, ll>> mv={{1,0}, {-1,0}, {0, -1}, {0, 1}};
void dfs(ll i, ll j)
{
    cnt+=s[i][j];
    s[i][j]=0;// working link vis[] array 
   for(ll k=0; k<4; k++)
   {
      if(is_valid(i+mv[k].first, j+mv[k].second))
      {
        dfs(i+mv[k].first, j+mv[k].second);
      }
   }
}
void solve(ll tc)
{
   ll n, m;
   cin>>n>>m;
   row=n, col=m;
   for(ll i=0; i<n; i++){
    for(ll j=0; j<m; j++){
        cin>>s[i][j];
    }
   }
   ll mx=0;
   for(ll i=0; i<n; i++){
    for(ll j=0; j<m; j++){
        if(s[i][j]){
            cnt=0;
            dfs(i, j);
            mx=max(cnt, mx);
        }
    }
   }
   cout<<mx<<endl;
   
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

