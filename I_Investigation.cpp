
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
ll a, b, k, n;
ll dp[11][91][91][3];
ll func(string &s, ll ind, ll sum, ll num, ll ty){
    if(ind==n){
        if(sum==0 and num==0)return 1;
        else return 0;
    }
    ll &res=dp[ind][sum][num][ty];
    if(res!=-1)return res;
    ll ans=0, dg=9;
    if(!ty)dg=s[ind]-'0';
    for(ll i=0; i<=dg; i++){
        ans+=func(s, ind+1, (sum+i)%k, (num*10+i)%k, ty|(i<dg));
    }
    return res=ans;
}
void solve(ll tc)
{
    cout<<"Case "<<tc<<": ";
    cin>>a>>b>>k;
    if(k>90){
        cout<<0<<endl;
        return;
    }
    a--;
    ll ans=0;
    string s=to_string(a);
    n=s.size();
    memset(dp, -1, sizeof(dp));
    ans-=func(s, 0, 0, 0, 0);
    s=to_string(b);
    n=s.size();
    memset(dp, -1, sizeof(dp));
    ans+=func(s, 0, 0, 0, 0);
    cout<<ans<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

