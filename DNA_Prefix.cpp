
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 5e4 + 10, inf=2e18;
ll mod = 1000000007;
vector<ll>power_p(50);
void precal(){
    power_p[0]=1;
    for(ll i=1; i<50; i++){
        power_p[i]=(power_p[i-1]*i)%mod;
    }
}
void solve(ll tc)
{
    ll n;
    cin>>n;
    vector<ll>hash(n,0);
    vector<string>st(n);
    ll mi=INT64_MAX;
    for(ll i=0; i<n; i++){
        cin>>st[i];
        mi=min(mi, (ll)st[i].size());
    }
    ll ans=0;
    //cout<<mi<<endl;;
    for(ll i=0; i<mi; i++){
        set<ll>stt;
        for(ll j=0; j<n; j++){
            hash[j]=(hash[j]+((st[j][i]-'A')*(power_p[i]))%mod)%mod;
            stt.insert(hash[i]);
        }
        if(stt.size()!=1)break;
        ans=i+1;
    }
    cout<<ans*n<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    precal();
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

