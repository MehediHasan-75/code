#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll block_size, sum=0;
ll v[200005];
ll mp[1000005];
struct Query{
    ll l, r, ind;
    bool operator<(Query other) const
    {
        if(l/block_size != other.l/block_size)
            return l<other.l;
        return (l/ block_size & 1) ? (r < other.r) : (r > other.r);
    }
};
void add(ll ind){
    sum-=(mp[v[ind]]*mp[v[ind]]*v[ind]);
    mp[v[ind]]++;
    sum+=(mp[v[ind]]*mp[v[ind]]*v[ind]);
}
void remove(ll ind){
    sum-=(mp[v[ind]]*mp[v[ind]]*v[ind]);
    mp[v[ind]]--;
    sum+=(mp[v[ind]]*mp[v[ind]]*v[ind]);
}
ll get_answer(){
    // cout<<sum<<endl;
    return sum;
}
void mo_s_algorithm(vector<Query> &queries) {
    vector<ll> answers(queries.size());
    sort(queries.begin(), queries.end());
    // TODO: initialize data structure
    //VVI
    ll cur_l = queries[0].l;
    ll cur_r = queries[0].l;
    mp[v[cur_l]]++;
    sum=v[cur_l];
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
        answers[q.ind] = get_answer();
    }
    for(auto &it: answers)cout<<it<<endl;
}
int main(){
    ll n;
    scanf("%lld", &n);
    block_size=sqrt(n);
    ll q;
    scanf("%lld", &q);
    for(ll i=0; i<n; i++)scanf("%lld", &v[i]);
    // cout<<n<<q<<endl;
    // for(ll i=0; i<n; i++)cout<<v[i]<<" ";
    vector<Query>queries(q);
    for(ll i=0; i<q; i++){
        ll l, r;
        scanf("%lld %lld", &l, &r);
        l--, r--;
        queries[i]={l, r, i};
    }
    mo_s_algorithm(queries);
}