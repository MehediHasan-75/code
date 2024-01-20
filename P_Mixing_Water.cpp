
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
double func(double h, double c, ll num, double tt){
    //cout<<num<<"\n";
    double t=h*(num/2 + num%2) - c*(num/2);
    //cout<<h*(num/2 + num%2)<<" "<<c*(num/2)<<" "<<abs(tt-t/(num/2 + num%2))<<endl;
    return abs(tt-t/(num/2 + num%2))/h;
}
void solve(ll tc)
{
    ll h, c, t;
    cin>>h>>c>>t;
    //cout<<func(h, c, 1)<<endl;
    ll lo=1, hi=100, ans=0;
    while(hi>=lo){
        ll mid=(hi+lo)>>1;
        if(func(h, c, mid-1, t)>=func(h, c, mid, t)){
            ans=mid;
            lo=mid+1;
        }
        else hi=mid-1;
    }
    cout<<"ans= "<<ans<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

