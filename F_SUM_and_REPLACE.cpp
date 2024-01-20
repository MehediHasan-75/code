
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 1e6+10, inf=2e18;
ll mod = 1000000007;
vector<ll> primes;vector<ll> mark(N,0);
vector<ll> lp(N,0), hp(N,0);
void siv()
{
    mark[0]=mark[1]=1;
    for(ll i=2; i<=N; i++)
    {
        if(!mark[i])
        {
            lp[i]=hp[i]=i;
            for(ll j=2*i; j<=N; j+=i)
            {
                mark[j]=1;
                hp[j]=i;
                if(!lp[j])lp[j]=i;
            }
        }
    }
}
ll div(ll n)
{
    ll ans=1;
    while(n>1)
    {
        ll prime_div=lp[n];// we can also use hp[n]
        ll cnt=0;
        while(n%prime_div==0)
        {
            n/=prime_div;
            cnt++;
        }
        ans*=(cnt+1);
    }
    return ans;
}
vector<ll>tree(N*4,0), v(N);
void build(ll node, ll st, ll en){
    if(st==en){
        tree[node]=v[st];
        return;
    }
    ll mid=(st+en)>>1;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
}
void update(ll node, ll st, ll en, ll l, ll r, ll val){
    if(en<l or r<st)return;
    if(st>=l and en<=r){
        tree[node]+=val;
        return;
    }
    ll mid=(st+en)>>1;
    update(2*node, st, mid, l , r, val);
    update(2*node+1, mid+1, en, l , r, val);
}
/**/
ll query(ll node, ll st, ll en, ll ind){
    if(st==en)return tree[node];
    ll mid=(st+en)>>1;
    if(ind<=mid){
        return tree[node]+query(2*node, st, mid, ind);
    }
    else{
        return tree[node]+query(2*node+1, mid+1, en, ind);
    }
}
void solve(ll tc)
{
    ll n, q;
    cin>>n;
    for(ll i=0; i<n; i++)cin>>v[i];
    build(1, 0, n-1);
    while(q--){
        ll type;
        cin>>type;
        //if(type==1)update(1, 0, n-1, l, r, )
    }
}
int main()
{
    fastio;ll T = 1;
    //cin >> T;
    siv();
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

