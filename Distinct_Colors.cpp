#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define ll long long
vector<ll>graph[N], tree(4*N, 0), color(N, 0), start(N), sz(N, 0), v;
ll timer=1;

map<ll,ll>mp1;
ll mp2[N];

void dfs(ll u, ll par){
    start[u]= timer++;
    // cout<<u<<" ";
    v.push_back(mp1[color[u]]);
    for(auto &v: graph[u]){
        if(v==par)continue;
        dfs(v, u);
        sz[u]+=sz[v]+1;
    }
}

ll cnt=1;
void remove(ll idx){
    mp2[v[idx]]--;
    if(mp2[v[idx]]==0)cnt--;
}  // TODO: remove value at idx from data structure
void add(ll idx){
    mp2[v[idx]]++;
    if(mp2[v[idx]]==1)cnt++;
}     // TODO: add value at idx from data structure
ll get_answer(){
    return cnt;
}
ll block_size;
 
struct Query {
    ll l, r, idx;
    bool operator<(Query other) const
    {
        if(l/block_size != other.l/block_size)
            return l<other.l;
        return (l/ block_size & 1) ? (r < other.r) : (r > other.r);
    }
};
void mo_s_algorithm(vector<Query> &queries) {
    vector<ll> answers(queries.size());
    sort(queries.begin(), queries.end());
 
    mp2[v[queries[0].l]]++;
    ll cur_l = queries[0].l;
    ll cur_r = queries[0].l;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    for(auto &it: answers)cout<<it<<" ";
}
int main(){
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    block_size=sqrt(n);
    ll counter=1;
    for(ll i=1; i<=n; i++){
        cin>>color[i];
        if(!mp1.count(color[i]))mp1[color[i]]=counter++;
    }
    for(ll i=1; i<n; i++){
        ll u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, -1);
    vector<Query>queries;
    for(ll i=0; i<n; i++){
        ll l=start[i+1], r=start[i+1]+sz[i+1];
        l--, r--;
        Query q={l, r, i};
        queries.push_back(q);
    }
    mo_s_algorithm(queries);
    // cout<<endl;
}