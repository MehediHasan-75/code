#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=30;
map<string , ll>mp;

void solve(ll tc, ll n){
    cout<<"Case "<<tc<<": ";
    for(ll i=0; i<n; i++){
        string s;
        cin>>s;

        mp[s]=i;
    }
    vector<vector<double>>adj(n, vector<double>(n, 0));
    for(ll i=0; i<n; i++)adj[i][i]=1;
    ll q;
    cin>>q;
    while(q--){
        string su, sv;
        double cost;
        cin>>su>>cost>>sv;

        ll u=mp[su], v=mp[sv];
        // cout<<u<<" "<<v<<" "<<cost<<endl;
        adj[u][v]=max(adj[u][v], cost);
    }

    for(ll k=0; k<n; k++){
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                adj[i][j]=max(adj[i][j], adj[i][k]*adj[k][j]);
            }
        }
    }
    for(ll i=0; i<n; i++){
        if(adj[i][i]>1){
            cout<<"Yes\n";
            return;
        }
    }
    cout << "No\n";
}
int main(){
    ll tc=1;
    while(1){
        ll n;
        cin>>n;
        if(n!=0)solve(tc++, n);
        else break;
    }
}