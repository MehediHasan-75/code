#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
vector<ll>value(N), parent(N), parentforValue(N);

//value will store exact value for each disjoint set's parent
//parentforValue will store if a value is now exist in the array what will be it's first occurance (this will be parent) else -1

ll find_parent(ll u){
    return parent[u]==u? u: parent[u]=find_parent(parent[u]);
}
void Union(ll u, ll v){
    u=find_parent(u), v=find_parent(v);
    if(u==v)return;
    parent[v]=u;
}

void UnionParentValue(ll x, ll y){
    ll p1=parentforValue[x], p2=parentforValue[y];

    if(p1==-1 or p1==p2)return;

    if(p2==-1){
        parentforValue[y]=p1;
        value[p1]=y;
        parentforValue[x]=-1;
        return;
    }
    parent[p1]=p2;
    parentforValue[x]=-1;
}
void solve(ll tc){
    cout<<"Case "<<tc<<":\n";
    ll n, m;
    cin>>n>>m;

    for(ll i=1; i<N; i++){
        parent[i]=i;
        parentforValue[i]=-1;
    }

    for(ll i=1; i<=n; i++){
        ll x;
        cin>>x;
        value[i]=x;
        if(parentforValue[x]==-1){
            parentforValue[x]=i;
        }
        else{
            Union(parentforValue[x], i);
        }
    }

    while(m--){
        ll type;
        cin>>type;
        if(type==1){
            ll u, v;
            cin>>u>>v;

            UnionParentValue(u, v);
        }
        else{
            ll ind;
            cin>>ind;
            cout<<value[find_parent(ind)]<<endl;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++)solve(i);
}