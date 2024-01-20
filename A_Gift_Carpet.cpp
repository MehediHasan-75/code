
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
    ll row, col;
    cin>>row>>col;
    string s[row];
    for(auto &it: s)cin>>it;
    // prnt(s);
    ll cnt=0;
    string st="vika";
    ll ind=0;
    for(ll i=0; i<col; i++){
        if(ind==4)break;
        for(ll j=0; j<row; j++){
            if(ind==4)break;
            if(s[j][i]==st[ind]){
                ind++;
                break;
            }
        }
    }
    if(ind==4)cout << "YES\n";
    else cout << "NO\n";
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

