
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define ll long long
ll row, col;
string s[1005];
bool is_valid(ll r, ll c)
{
    if(r<0 or c<0 or r>=row or c>=col or s[r][c]!='.' )return false;// s[r][c]='.' means desired element in matrix.
    return true;
}
vector<pair<ll, ll>> mv={{1,0}, {-1,0}, {0, -1}, {0, 1}};
void dfs(ll i, ll j)
{
    s[i][j]='X';// working link vis[] array 
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
    cin>>row>>col;
    for(ll i=0; i<row; i++)cin>>s[i];
    ll cnt=0;
    for(ll i=0; i<row; i++){
        for(ll j=0; j<col; j++){
            if(s[i][j]=='.'){
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}
int main()
{
    fastio;ll T = 1;
    //cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

