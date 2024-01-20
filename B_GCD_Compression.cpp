
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
    vector<ll>even, odd;
    for(ll i=0; i<n+n; i++){
        ll a;
        cin>>a;
        if(a%2==0)even.push_back(i+1);
        else odd.push_back(i+1);
    }
    if(odd.size()%2)odd.pop_back(), even.pop_back();
    else{
        if(odd.size()>=2)odd.pop_back(), odd.pop_back();
        else even.pop_back(), even.pop_back();
    }
    //cout<<odd.size()<<" "<<even.size()<<endl;
    if(even.size())for(ll i=0; i<even.size()-1; i+=2)cout<<even[i]<<" "<<even[i+1]<<endl;
    if(odd.size())for(ll i=0; i<odd.size()-1; i+=2)cout<<odd[i]<<" "<<odd[i+1]<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

