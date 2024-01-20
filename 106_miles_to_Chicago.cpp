#include <bits/stdc++.h>
using namespace std;
const int N = 101;
#define ll long long

int main()
{
    while (1)
    {
        ll n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        ll m;
        cin >> m;

        vector<vector<double>>adj(n, vector<double>(n, 0));

        for(ll i=0; i<m; i++){
            ll u, v;
            double cost;
            cin>>u>>v>>cost;
            u--, v--;
            adj[u][v]=adj[v][u]=max(adj[u][v], cost/100);
        }

        for(ll k=0; k<n; k++){
            for(ll i=0; i<n; i++){
                for(ll j=0; j<n; j++){
                    adj[i][j]=max(adj[i][j], (adj[i][k]*adj[k][j]));
                }
            }
        }
        double ans=adj[0][n-1]*100;
        cout<<fixed<<setprecision(6);
        cout<<ans<<" percent\n";
    }
}