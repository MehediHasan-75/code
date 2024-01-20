
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
bool func(vector<ll>&v, ll dist, ll cow){
    ll cnt=1, l=0;
    for(ll r=0; r<v.size(); r++){
        if(v[r]-v[l]>=dist){
            cnt++;
            l=r;
        }
    }
    //cout<<cnt<<" "<<dist<<endl;
    return cnt>=cow;
}
void solve(ll tc)
{
   ll points, cow;
   cin>>points>>cow;
   vector<ll>v(points);
   for(auto &it: v)cin>>it;
   sort(all(v));
   ll lo=0,  hi=1e9+10, ans=-1;
   while(hi>=lo){
    ll mid=(hi+lo)>>1;
    if(func(v, mid, cow))ans=mid, lo=mid+1;
    else hi=mid-1;
   } 
   cout<<ans<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

