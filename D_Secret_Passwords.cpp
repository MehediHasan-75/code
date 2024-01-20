#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=30;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define endl '\n'
vector<ll>graph[N], vis(N, 0);

void dfs(ll u){
    vis[u]=1;

    for(auto &v: graph[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}
int main(){
    ll n;
    cin>>n;
    vector<ll>chkk(26, 0), st;
    for(ll i=0; i<n; i++){
        string s;
        cin>>s;
        vector<ll>chk(26, 0);

        vector<ll>stt;
        for(auto &it: s)if(chk[it-'a']==0)stt.push_back(it), chk[it-'a']=1;
        for(auto &it1: stt){
            for(auto &it2: stt){
                ll u=it1-'a', v=it2-'a';
                if(chkk[u]==0)st.push_back(u), chkk[u]=1;
                if(chkk[v]==0)st.push_back(v), chkk[v]=1;

                if(it1==it2)continue;

                auto x=find(graph[u].begin(), graph[u].end(), v), y=find(graph[v].begin(), graph[v].end(), u);
                if(x==graph[u].end()) graph[u].push_back(v);
                if(y==graph[v].end())graph[v].push_back(u);
            }
        }
    }
    ll cnt=0;

    for(auto &node: st){
        if(!vis[node]){
            cnt++;
            dfs(node);
        }
    }
    cout<<cnt<<endl;
    
}