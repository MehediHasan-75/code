
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
   string s1, s2;
   cin>>s1>>s2;
   if(s1==s2){
    cout << "Yes\n";
   }
   else{
    string ev1, ev2, od1, od2;
    for(auto &it: s1){
        if((it-'a')%2==0)ev1.push_back(it);
        else od1.push_back(it);
    }
    for(auto &it: s2){
        if((it-'a')%2==0)ev2.push_back(it);
        else od2.push_back(it);
    }
    if(od1==od2 and ev1==ev2)cout<<"Yes\n";
    else cout<<"No\n";
   }
}
int main()
{
    fastio;ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

