
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
ll val(ll n){
    return n*(n+1)/2;
}
void solve(ll tc)
{
    ll n, k;
    cin>>n>>k;
    ll mida=0;
    for(ll i=0; i<=n-2; i++){
        if(val(i+1)>=k){
            mida=i;
            break;
        }
    }
    ll left=n-mida-2;
    while(left--)cout<<'a';
    cout<<'b';
    ll enda=0;
    for(ll i=val(mida)+1; i<k; i++){
        enda++;
        mida--;
    }
    while(mida--)cout<<'a';
    cout<<'b';
    while(enda--)cout<<'a';
    cout<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

