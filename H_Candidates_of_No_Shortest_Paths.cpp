#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll INF=1e18;
const int N=105;
ll d[N][N], mrk[N][N];// adj matrix(if edge exist wt or 1 and if dosent infinity and s[i][i]=0
ll nxt[N][N];// initially next[i][j]=j;
ll v, e;
void floyed_warshal()
{
    for (int k = 0; k < v; ++k) {
        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j) {
                if (d[i][k] < INF && d[k][j] < INF)// safe from negative edges problem (reduce infinity though path dosent exist)
                    if(d[i][k] + d[k][j]<d[i][j])
                    {
                        d[i][j]=d[i][k] + d[k][j];
                        nxt[i][j]=nxt[i][k];//stores if we want to go node j form i what will be our next step.
                    }
            }
        }
    }
}

vector<ll>find_path(ll i, ll j)
{
    vector<ll> path;
    path.push_back(i);
    while(i!=j)// while we won'n reach node j.
    {
        i=nxt[i][j];
        path.push_back(i);
    }
    return path;
}
map<pair<ll,ll>,ll>mp;
int main(){
    cin>>v>>e;

    for(ll i=0; i<e; i++){
        ll x, y, w;
        cin>>x>>y>>w;
        x--, y--;
        d[x][y]=d[y][x]=w;
        mp[{x, y}]=w;
    }
    for(ll i=0; i<v; i++){
        for(ll j=0; j<v; j++){
            if(d[i][j]==0)d[i][j]=INF;
            nxt[i][j]=j;
        }
        d[i][i]=0;

    }
    ll cnt=0;
    floyed_warshal();

    for(auto &it:mp){
        ll u=it.first.first, v=it.first.second, w=it.second;
        if(d[u][v]!=w)cnt++;
    }
    cout<<cnt<<endl;
}