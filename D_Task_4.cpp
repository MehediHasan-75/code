
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
    vector<ll>v;

    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        v.push_back(a);
    }

    ll q;
    cin>>q;
    while(q--){
        ll a;
        cin>>a;
        auto it=lower_bound(v.begin(), v.end(), a);

        if((*it)==a)cout<<"Yes ";
        else cout<<"No ";
        cout<<it-v.begin()+1<<endl;
    }
}
int main()
{
    fastio;ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

