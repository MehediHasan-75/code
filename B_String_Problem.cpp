#include<bits/stdc++.h>
using namespace std;
const int N=28;
#define ll long long
vector<vector<ll>>adj(N, vector<ll>(N, 1e14));

int main(){
    string s, t;
    cin>>s>>t;
    if(s.size()!=t.size()){
        cout<<-1<<endl;
        return 0;
    }
    ll n;
    cin>>n;
    for(ll i=0; i<26; i++)adj[i][i]=0;
    for(ll i=0; i<n; i++){
        char a, b;
        ll u, v, w;
        cin>>a>>b>>w;
        u=a-'a', v=b-'a';

        adj[u][v]=min(adj[u][v], w);
    }
    for(ll k=0; k<26; k++){
        for(ll i=0; i<26; i++){
            for(ll j=0; j<26; j++){
                adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
    ll cost=0;
    string ans="";
    for(ll i=0; i<s.size(); i++){
        ll u=s[i]-'a', v=t[i]-'a';

        ll temp=1e9+10, ch=-1;

        for(ll x=0; x<26; x++){
            if(adj[u][x]+adj[v][x]<temp){
                temp=adj[u][x]+adj[v][x];
                ch=x;
            }
        }
        if(ch==-1){
            cout<<-1<<endl;
            return 0;
        }
        ans+=(char)(ch+'a');
        cost+=temp;
    }
    cout<<cost<<endl;
    cout<<ans<<endl;
}