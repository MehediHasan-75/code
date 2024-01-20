
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
    vector<ll>v(n);
    map<ll,ll>mp1, mp2;
    for(auto &it: v)cin>>it, mp1[it]++;
    ll len=n;
    for(ll j=n; j>=1; j--){
        ll lo=0, hi=n-1, ind=-1;
        while(hi>=lo){
            ll mid=(hi+lo)>>1;
            if(v[mid]<j){
                hi=mid-1;
            }
            else lo=mid+1, ind=mid+1;
        }
        if(v[j-1]!=ind){
            cout << "NO\n";
            return;
        }
        // cout<<j<<" "<<ind<<endl;
    }
    cout << "YES\n";
    
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

