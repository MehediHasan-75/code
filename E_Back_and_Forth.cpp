
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

string func(string s){
    string ans;
    for(auto &it: s){
        if(it=='U')ans.push_back('D');
        if(it=='D')ans.push_back('U');
        if(it=='L')ans.push_back('R');
        if(it=='R')ans.push_back('L');
    }
    return ans;
}
void solve(ll tc)
{
    ll x, y, xt, yt;
    cin>>x>>y>>xt>>yt;
    string s="", temp;
    for(ll i=0; i<abs(x-xt); i++){
        temp.push_back('R');
    }
    for(ll i=0; i<abs(y-yt); i++){
        temp.push_back('U');
    }
    // cout<<temp<<endl;
    s+=temp;
    s+=func(temp);
    temp.clear();

    temp.push_back('L');
    for(ll i=0; i<=abs(y-yt); i++){
        temp.push_back('U');
    }
    for(ll i=0; i<=abs(x-xt); i++){
        temp.push_back('R');
    }
    temp.push_back('D');
    s+=temp;
    // cout<<s<<endl;
    s+=func(temp);
    cout<<s<<endl;

}
int main()
{
    fastio;ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

