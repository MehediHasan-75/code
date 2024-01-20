#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
vector<ll>parent(N);
ll find_parent(ll u){
    return parent[u]==u? u: parent[u]=find_parent(parent[u]);
}
void merge(ll u, ll nw){
    nw = find_parent(nw);
    if(parent[u] == u){
        parent[u] = nw;
    }
}

void solve(ll tc){
    cout<<"Case "<<tc<<": \n";
    ll n, q;
    cin>>n>>q;

    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    for(ll i=1; i<N; i++)parent[i]=i;
    while(q--){
        ll type;
        cin>>type;

        if(type==2){
            ll ind;
            cin>>ind;
            ind--;
            cout<<find_parent(v[ind])<<endl;
        }
        else{
            ll prev, nw;
            cin>>prev>>nw;
            merge(prev, nw);
        }
    }
}
int main(){
    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++)solve(i);
}