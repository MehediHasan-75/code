
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
    string s[n];
    for(auto &it: s)cin>>it;
    // for(auto &it: s)cout<<it<<endl;
    for(ll row=0; row<n; row++){
        ll cnt=0;
        for(ll col=0; col<m; col++){
            if(s[row][col]=='U')cnt++;
        }
        if(cnt%2){
            cout<<-1<<endl;
            return;
        }
        ll white=cnt/2, black=cnt/2;
        // cout<<white<<" "<<black<<endl;
        for(ll col=0; col<m; col++){
            if(s[row][col]=='U'){
                if(white>0)s[row][col]='W',s[row+1][col]='B', white--;
                else s[row][col]='B',s[row+1][col]='W', black--;
            }
        }
    }
    for(ll col=0; col<m; col++){
        ll cnt=0;
        for(ll row=0; row<n; row++){
            if(s[row][col]=='L')cnt++;
        }
        if(cnt%2){
            cout<<-1<<endl;
            return;
        }
        ll white=cnt/2, black=cnt/2;
        for(ll row=0; row<n; row++){
            if(s[row][col]=='L'){
                if(white>0)s[row][col]='W',s[row][col+1]='B', white--;
                else s[row][col]='B', s[row][col+1]='W', black--;
            }
        }
    }
    for(auto &it: s)cout<<it<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

