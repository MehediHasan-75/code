
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 1e5 + 10, inf=2e18;
ll mod = 1000000007;
struct  nd{
    ll pre, suff, val, ans;
};

vector<ll>v(N);
vector<nd> tree(N*4);
nd combine(nd l, nd r){
    nd res;
    res.val = l.val + r.val;
    res.pre = max(l.pre, l.val + r.pre);
    res.suff = max(r.suff, r.val + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pre);
    return res;
}
void build(ll node, ll st, ll en){
    if(st==en){
        tree[node]={max(0ll, v[st]),max(0ll, v[st]), v[st], max(0ll, v[st]) };
        return;
    }
    ll mid=(st+en)>>1;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    tree[node]=combine(tree[2*node], tree[2*node+1]);
}
void update(ll node, ll st, ll en, ll ind, ll val){
    if(st==en){
        v[st]=val;
        tree[node]={max(0ll, v[st]),max(0ll, v[st]), v[st], max(0ll, v[st]) };
        return;
    }
    ll mid=(st+en)>>1;
    if(ind<=mid){
        update(2*node, st, mid, ind, val);
    }
    else update(2*node+1, mid+1, en, ind, val);
    tree[node]=combine(tree[2*node], tree[2*node+1]);
}
void solve(ll tc)
{
    ll n,  q;
    cin>>n>>q;
    for(ll i=0; i<n; i++)cin>>v[i];
    build(1, 0, n-1);
    cout<<tree[1].ans<<endl;
    while(q--){
        ll ind, val;
        cin>>ind>>val;
        update(1, 0, n-1, ind, val);
        cout<<tree[1].ans<<endl;
    }

}
int main()
{
    fastio;ll T = 1;
    //cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

