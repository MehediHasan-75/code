
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 101, inf=2e18;
ll mod = 1000000007;
void solve(ll tc)
{
    ll n;
    cin>>n;
    vector<ll>ans(n, 1);

    vector<ll>v[N];

    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        v[a].push_back(i);
    }
    ll k=2;
    for(ll i=1; i<N; i++){
        if(v[i].size()>=2){
            ans[v[i][0]]=k;
            k++;
        }
        if(k>3)break;
    }

    if(k<=3){
        cout<<-1<<endl;
    }
    else{
        for(ll i=0; i<n; i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

