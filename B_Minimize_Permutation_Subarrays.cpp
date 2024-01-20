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
    ll n;
    cin>>n;
    ll on, tw, nn;
    vector<pair<ll,ll>>v(n);
    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        v[i]={a,i};
        if(a==1)on=i+1;
        if(a==2)tw=i+1;
        if(a==n)nn=i+1;
    }
    if(on<nn and tw<nn){
        if(on>tw)cout<<on<<" "<<nn<<endl;
        else cout<<tw<<" "<<nn<<endl;
    }
    else if(on>nn and tw>nn){
        if(on>tw)cout<<tw<<" "<<nn<<endl;
        else cout<<on<<" "<<nn<<endl;
    }
    else cout<<n<<" "<<n<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}