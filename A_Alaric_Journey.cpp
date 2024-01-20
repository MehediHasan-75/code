
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
    ll l=0, r=n-1, cnt=0;

    vector<ll>v(n);
    for(auto &it: v)cin>>it;

    while(l<r){
        while(l<r and v[l]<v[r]){
            l++;
            v[l]+=v[l-1];   
            cnt++;     
        }
        while(l<r and v[l]>v[r]){
            r--;
            v[r]+=v[r+1];
            cnt++;
        }
        if(l<r and v[l]==v[r])r--, l++;
    }
    cout<<cnt<<endl;
}
int main()
{
    fastio;ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

