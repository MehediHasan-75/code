
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
vector<ll>prefix_function(vector<ll>&v){
    ll n=v.size();
    vector<ll>pi(n, 0);
    for(ll i=1; i<n; i++){
        ll j=pi[i-1];
        while(j>0 and v[i]!=v[j]) j=pi[j-1];
        if(v[j]==v[i])j++;
        pi[i]=j;
    }
    return pi;
}
void solve(ll tc)
{
    ll n, m;
    cin>>n>>m;
    vector<ll>v1(n), v;
    for(auto &it: v1)cin>>it;
    for(ll i=0; i<m; i++){
        ll a;
        cin>>a;
        v.push_back(a);
    }
    v.push_back(-10000000);
    for(ll i=0; i<n; i++){
        v.push_back(v1[i]);
    }
    //prnt(v);
    vector<ll>pi=prefix_function(v);
    ll ind=-1;
    for(ll i=0; i<pi.size(); i++){
        if(pi[i]==m){
            ind=i; break;
        }
    }
    if(ind==-1)cout<<-1<<endl;
    else cout<<ind-2*m+1<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

