
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 1e6 + 10, inf=2e18;
ll mod = 1000000007;
vector<ll> primes;vector<ll> mark(N,0);
vector<ll> lp(N,0), hp(N,0);
void siv()
{
    mark[0]=mark[1]=1;
    for(ll i=2; i<=N; i++)
    {
        if(!mark[i])
        {
            lp[i]=hp[i]=i;
            for(ll j=2*i; j<=N; j+=i)
            {
                mark[j]=1;
                hp[j]=i;
                if(!lp[j])lp[j]=i;
            }
        }
    }
}
void pr_fact(ll n, map<ll,ll> &mp)
{
    while(n>1)
    {
        ll prime_div=lp[n];// we can also use hp[n]
        while(n%prime_div==0)
        {
            n/=prime_div;
            mp[prime_div]++;
        }
    }
}
void solve(ll tc)
{
    ll n;
    cin>>n;
    map<ll,ll>mp;
    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        pr_fact(a, mp);
    }
    for(auto &it: mp){
        if(it.second%n){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    // mp.clear();
}
int main()
{
    fastio;ll T = 1;
    siv();
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

