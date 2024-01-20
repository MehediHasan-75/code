
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
    ll n, a, q;
    cin>>n>>a>>q;
    ll can=a, has=a;
    string s;
    cin>>s;
    for(auto &it: s){
        if(it=='+')can++;
    }
    bool fl=false;
    if(has==n)fl=true;
    for(auto &it: s){
        if(it=='+')has++;
        else has--;
        if(has==n)fl=true;
    }
    if(fl)cout << "YES\n";
    else if(can>=n)cout<<"MAYBE\n";
    else cout << "NO\n";
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}
