#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll vis[201][201], rw[201], col[201];
string s[201];
vector<pair<ll, ll>> mv={{-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 1}};

ll n, m;

bool valid(ll x, ll y){
    return x>=0 and y>=0 and x<n and y<m and vis[x][y]==0;
}
//Black tries to join row 1 with row N
void dfs(ll x, ll  y){
    if(s[x][y]=='b')rw[x]=1;
    else col[y]=1;
    for(ll i=0; i<8; i++){
        ll xn=x+mv[i].first, yn=y+mv[i].second;

        if(valid(xn, yn)){
            // cout<<"Hi\n";
            if(s[x][y] == s[xn][yn]){
                vis[xn][yn]=1;
                dfs(xn, yn);
            }
        }
    }
}

int main(){

    ll cs=0;
    while(true){
        memset(vis, 0, sizeof(vis));
        cin>>n;
        m=n;
        if(n==m and n==0)break;
        cout<<++cs<<" ";
        for(ll i=0; i<n; i++)cin>>s[i];

        ll mx=0, fl=0;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                if(s[i][j]=='b' and !vis[i][j]){
                    vis[i][j]=1;
                    dfs(i, j);
                    ll cnt=0;
                    for(ll i=0; i<n; i++){
                        if(rw[i])cnt++;
                    }
                    if(cnt==n){
                        cout<<"B\n";
                        fl=1;
                        break;
                    }
                    memset(rw, 0, sizeof(rw));
                }
            }
            if(fl)break;
        }
        if(fl)continue;

        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                if(s[i][j]=='w' and !vis[i][j]){
                    vis[i][j]=1;
                    dfs(i, j);
                    ll cnt=0;
                    for(ll i=0; i<n; i++){
                        if(col[i])cnt++;
                    }
                    if(cnt==n){
                        cout<<"W\n";
                        fl=1;
                        break;
                    }
                    memset(col, 0, sizeof(col));
                }
            }
            if(fl)break;
        }
    }
}