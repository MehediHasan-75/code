#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll cnt;
#define N 100005
ll sz[N], parent[N];
void make_set(ll n){
    for(ll i=1; i<=n; i++){
        parent[i]=i;
        sz[i]=1;
    }
}
ll find_parent(ll u){
    if(parent[u]==u)return u;
    return parent[u]=find_parent(parent[u]);
}
void Unin(ll u, ll v){
    ll a=find_parent(u), b=find_parent(v);
    if(a==b)return;
    cnt--;
    if(sz[a]>sz[b])swap(a,b);
    sz[b]+=sz[a];
    parent[a]=b;
}
int main(){
    fastio;
    ll n, m;
    cin>>n>>m;
    // cout<<n<<" "<<m<<endl;
    make_set(n);
    cnt=n;
    vector<pair<ll,ll>>v(m+1);
    for(ll i=1; i<=m; i++){
        cin>>v[i].first>>v[i].second;
    }
    //for(auto &it: v)cout<<it.first<<" "<<it.second<<endl;
    ll q;
    cin>>q;
    vector<ll>mrk(N, 0), rmv(q);
    for(ll i=0; i<q; i++){
        cin>>rmv[i];
        mrk[rmv[i]]=1;
    }
    reverse(rmv.begin(), rmv.end());
    //for(auto &it: rmv)cout<<it<<" ";
    cout<<endl;
    for(ll i=1; i<=m; i++){
        if(!mrk[i]){
            Unin(v[i].first, v[i].second);
            //cout<<i<<" ";
        }
    }
    vector<ll>ans;
    ans.push_back(cnt);
    for(ll i=0; i<q-1; i++){
        ll ind=rmv[i];
        Unin(v[ind].first, v[ind].second);
        ans.push_back(cnt);
    }
    reverse(ans.begin(), ans.end());
    for(auto &it: ans)cout<<it<<" ";
}