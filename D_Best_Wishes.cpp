
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 2e6 + 10, inf=2e18;
ll mod = 1000000007;

ll par[N], cnt[N];
ll func(ll n){
    if(n==0)return 0;

    if(cnt[n]!=-1)return cnt[n];

    ll ans1=INT64_MAX, ans2=INT64_MAX, ans3=INT64_MAX;
    if(n%2==0)ans1=(func(n/2)+1);
    if(n%3==0) ans2=(func(n/3)+1);
    ans3=(func(n-1)+1);
    
    ll ans=min({ans1, ans2, ans3});

    if(ans1==ans)par[n]=n/2;
    else if(ans2==ans)par[n]=n/3;
    else par[n]=n-1;
    // cout<<n<<" "<<ans<<endl;
    return cnt[n]=ans;
}
void solve(ll tc)
{
    ll n;
    cin>>n;
    vector<ll>v;
    v.push_back(n);
    ll parent=n;
    while(parent!=1){
        v.push_back(parent=par[parent]);
    };
    reverse(all(v));
    cout<<v.size()<<endl;
    prnt(v);
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    memset(cnt, -1, sizeof(cnt));
    for(ll i=1; i<N; i++){
        func(i);
    }
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

