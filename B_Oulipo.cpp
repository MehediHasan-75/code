
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
ll pi_func(string s, ll m){
    ll cnt=0, n=s.size();
    vector<ll>pi(n,0);
    for(ll i=1; i<n; i++){
        ll j=pi[i-1];
        while(j>0 and s[i]!=s[j])j=pi[j-1];
        if(s[i]==s[j])j++;
        if(j==m)cnt++;
        pi[i]=j;
    }
    return cnt;
}
void solve(ll tc)
{
    string s1, s2;
    cin>>s1>>s2;
    string s=s1+"$"+s2;
    cout<<pi_func(s, s1.size())<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

