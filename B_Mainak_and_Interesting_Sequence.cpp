
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
    ll n, sm;
    cin>>n>>sm;
    if(n%2){
        ll last=sm-(n-1);
        if(last<=0)cout<<"No\n";
        else{
            cout<<"Yes\n";
            for(ll i=0; i<n-1; i++)cout<<1<<" ";
            cout<<last<<endl;
        }
    }
    else{
        ll last2=sm-(n-2);
        if(last2<2 or last2%2!=0){
            cout<<"No\n";
        }
        else{
            cout<<"Yes\n";
            for(ll i=0; i<n-2; i++)cout<<1<<" ";
            cout<<last2/2<<" "<<last2/2<<endl;
        }
    }
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

