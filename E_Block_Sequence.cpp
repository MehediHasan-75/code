
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
vector<ll>v(N);
ll n;
ll removed[N];
ll func(ll ind){
    if(ind==n)return 0;
    if(removed[ind]!=-1)return removed[ind];
    ll mi=INT64_MAX;

    if(ind+v[ind]<n){
        mi=min(func(ind+v[ind]+1), 1+func(ind+1));
    }
    else mi= 1+func(ind+1);
    return removed[ind]=mi;
}
void solve(ll tc)
{
    cin>>n;
    memset(removed, -1, sizeof(removed));
    // cout<<n<<endl;
    for(ll i=0; i<n; i++)cin>>v[i];

    cout<<func(0)<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

