#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=2e5+10;

vector<ll>graph[N];
vector<ll>col(N, -1), cl(2, 0);

void dfs(int u, int c) {
    col[u] = c;// here color c=0 or 1
    cl[c]++;
    for (auto v : graph[u]) {
        if (col[v] == -1) {
            dfs(v, c ^ 1);
        }
    }
}
int main(){
    ll n;
    cin>>n;
    for(ll i=0; i<n-1; i++){
        ll u, v;
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);
    cout<<min(cl[0], cl[1])-1<<endl;
}