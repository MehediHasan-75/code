#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=5e5+10;
ll number[33][N], vs;
// int compare(int i, int j, int l, int k) {
//     pair<int, int> a = {c[k][i], c[k][(i+l-(1 << k))%n]};
//     pair<int, int> b = {c[k][j], c[k][(j+l-(1 << k))%n]};
//     return a == b ? 0 : a < b ? -1 : 1;
// }
bool cmp(pair<ll,ll>&p1, pair<ll,ll>&p2){
    ll i=p1.first, j=p2.first, l=min(p1.second-p1.first+1, p2.second-p2.first+1);
        ll k=log2(l);
        pair<int, int> a = {number[k][i], number[k][(i+l-(1 << k))%vs]};
        pair<int, int> b = {number[k][j], number[k][(j+l-(1 << k))%vs]};
        if(a!=b)return a<b;
        if(p1.second-p1.first+1 == p2.second-p2.first+1)return p1<p2;
        return p1.second-p1.first+1 < p2.second-p2.first+1;
}
void radixSort(vector<pair< pair<ll,ll>, ll> > &v){
    ll n=v.size();
    vs=n;
    {
        vector<pair< pair<ll,ll>, ll> > v_new(n);
        vector<ll>cnt(n, 0), bucket(n);
        for(ll i=0; i<n; i++)cnt[v[i].first.second]++;

        bucket[0]=0;
        for(ll i=1; i<n; i++)bucket[i]= bucket[i-1]+cnt[i-1];

        for(auto &it: v){
            ll x=it.first.second;
            v_new[bucket[x]]=it;
            bucket[x]++;
        }
        v=v_new;
    }
    {
        vector<pair< pair<ll,ll>, ll> > v_new(n);
        vector<ll>cnt(n, 0), bucket(n, 0);
        for(ll i=0; i<n; i++)cnt[v[i].first.first]++;

        bucket[0]=0;
        for(ll i=1; i<n; i++)bucket[i]= bucket[i-1]+cnt[i-1];

        for(auto &it: v){
            ll x=it.first.first;
            v_new[bucket[x]]=it;
            bucket[x]++;
        }
        v=v_new;
    }
}
void suffixArray(string &s){
    s+=" ";
    ll n=s.size();
    vector<ll>array(n);

    vector<pair<char, ll>>v(n);
    
    for(ll i=0; i<n; i++)v[i]={s[i], i};
    sort(v.begin(), v.end());

    number[0][v.front().second]=0;

    ll k=0;
    for(ll i=1; i<n; i++){
        if(v[i-1].first==v[i].first)number[k][v[i].second]=number[k][v[i-1].second];
        else number[k][v[i].second]=number[k][v[i-1].second]+1;
    }
    // for(ll i=0; i<n; i++)cout<<number[k][i]<<" ";
    while((1ll<<k)<= n){
        vector<pair< pair<ll,ll>, ll> > v(n);
        for(ll i=0; i<n; i++){
            v[i]={ {number[k][i], number[k][(i+(1ll<<k))%n]}, i};
        }
        radixSort(v);
        for(ll i=0; i<n; i++)array[i]=v[i].second;
        number[k+1][v.front().second]=0;

        for(ll i=1; i<n; i++){
            if(v[i-1].first==v[i].first)number[k+1][v[i].second]=number[k+1][v[i-1].second];
            else number[k+1][v[i].second]=number[k+1][v[i-1].second]+1;
        }

        k++;
    }
    // for(ll i=0; i<n; i++)cout<<s.substr(array[i], n-array[i])<<" "<<number[k][i]<<endl;
    // cout<<endl;

    vector<ll>lcp(n+1, 0);
    ll matched=0;
    for(ll i=0; i<n-1; i++){
        ll pos_i=number[k][i], j= array[pos_i-1];
        while(s[i+matched]==s[j+matched])matched++;
        lcp[pos_i]=matched;
        matched=max(0ll, matched-1);
    }
    // for(ll i=0; i<n-1; i++)cout<<lcp[i]<<" ";
    // cout<<endl;
    cin>>n;
    // cout<<n<<endl;
    vector<pair<ll,ll>>vv(n);
    for(ll i=0; i<n; i++){
        cin>>vv[i].first>>vv[i].second;
        vv[i].first--, vv[i].second--;
    }
    // for(auto &it: vv)cout<<it.first<<" "<<it.second<<endl, it.first--, it.second--;
    // cout<<endl;
    sort(vv.begin(), vv.end(), cmp);
    for(auto &it: vv)cout<<it.first+1<<" "<<it.second+1<<endl;
    
}
int main(){
    string s;
    cin>>s;

    suffixArray(s);
}