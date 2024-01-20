#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;

vector<ll>parent(N), sz(N, 1);

ll find_parent(ll u){
    return parent[u]==u? u: parent[u]=find_parent(parent[u]);
}
void Union(ll u, ll v){
    u=find_parent(u), v=find_parent(v);

    if(u==v)return;
    if(sz[u]<sz[v])swap(u, v);

    sz[u]+=sz[v];
    parent[v]=u;
    return;
}
void solve(ll tc){
    cout<<"Case "<<tc<<":\n";
    // cout<<"Case "<<tc<<": \n";
    string s;
    cin>>s;
    string s1=s;
    
    ll n;
    cin>>n;

    vector<pair<ll,ll>>query(n);

    for(ll i=0; i<n; i++){
        ll type, ind;
        cin>>type>>ind;
        query[i]={type, ind};
        if(type==2){
            s1[ind]='#';
        }
    }
    // cout<<s1<<endl;
    for(ll i=0; i<s.size(); i++)parent[i]=i, sz[i]=1;

    for(ll i=0; i<s.size()-1; i++){
        if(s1[i]==s1[i+1] and s1[i]!='#'){
            Union(i, i+1);
        }
    }
    reverse(query.begin(), query.end());
    vector<ll>ans;
    for(ll i=0; i<query.size(); i++){
        ll type=query[i].first, ind=query[i].second;

        if(type==1){
            ans.push_back(sz[find_parent(ind)]);
        }
        else{
            if(ind-1>=0 and s[ind-1]==s[ind])Union(ind, ind-1);
            if(ind+1<s.size() and s[ind+1]==s[ind])Union(ind, ind+1);
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto &it: ans)cout<<it<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++)solve(i);
}