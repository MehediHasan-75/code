
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
bool func(ll a, ll b, ll c, ll group){
    ll can_b=b;
    if(a<group){
        ll x=min(b, group-a);
        b-=x;
        a+=x;
    }
    if(c<group){
        ll x=min(b, group-c);
        b-=x;
        c+=x;
    }
    if(c>group){
        ll x=c-group;
        c=group;
        b+=x;
    }
    else if(a>group){
        ll x=a-group;
        a=group;
        b+=x;       
    }
    //cout<<a<<" "<<b<<" "<<c<<endl;
    return (a<=group and b<=group and c<=group);
}
void solve(ll tc)
{
    ll a, b, c;
    cin>>a>>b>>c;
    ll lo=0, hi=1e9+10, ans=0;
    while(hi>=lo){
        ll mid=(hi+lo)>>1;
        if(func(a, b, c, mid)){
            ans=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    cout<<ans<<endl;
    //cout<<func(a, b, c, 392);
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

