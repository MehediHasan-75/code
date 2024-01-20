#include<bits/stdc++.h>
using namespace std;
#define  ll long long
const int N=2e5+10;
#define mod 1000000007
vector<ll>graph[N], sub_sz(N, 1), szz;
ll n;

void dfs1(ll u, ll p){
    for(auto &v: graph[u]){
        if(v==p)continue;
        dfs1(v, u);

        sub_sz[u]+=sub_sz[v];
    }
}
void dfs2(ll u, ll p){
    // cout<<sub_sz[u]<<endl;
    for(auto &v: graph[u]){
        if(v==p)continue;
        szz.push_back((n-sub_sz[v])*sub_sz[v]);
        dfs2(v, u);
    }
}
void clr(ll n){
    for(ll i=0; i<=n; i++)graph[i].clear(), sub_sz[i]=1;
    szz.clear();
}
void solve(){
    cin>>n;

    clr(n);

    for(ll i=0; i<n-1; i++){
        ll u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ll k;
    cin>>k;

    vector<ll>primes;
    for(ll i=0; i<k; i++){
        ll a;
        cin>>a;
        primes.push_back(a);
    }
    while(primes.size()<n-1){
        primes.push_back(1);
    }
    sort(primes.begin(), primes.end());
    while(primes.size()>n-1){
      primes[primes.size()-2] = (primes[primes.size()-2] * primes.back())%mod;
      primes.pop_back();
    }

    dfs1(1, -1);
    dfs2(1, -1);

    sort(szz.begin(), szz.end());

    ll ans=0;
    // for(auto &it: szz)cout<<it<<" ";
    // cout<<endl;
    // for(auto &it: primes)cout<<it<<" ";
    for(ll i=0; i<n-1; i++){
        ans=(ans+ ((primes[i]%mod)*(szz[i]%mod)%mod))%mod;
    }
    cout<<ans<<endl;
    // cout<<"HI\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;

    while(t--)solve();
}