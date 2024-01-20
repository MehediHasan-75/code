#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 12;
string s[N];
vector<pair<ll, ll>> mv = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

ll n;
ll vis[N][N], level[N][N];

bool valid(ll x, ll y)
{
    return x < n and y < n and x >= 0 and y >= 0 and vis[x][y] == 0 and s[x][y] != '#';
}
ll ansx, ansy;
ll bfs(ll x, ll y, char dest)
{
    queue<pair<ll, ll>> qu;

    qu.push({x, y});
    vis[x][y] = 1;
    level[x][y] = 0;

    while (qu.size())
    {
        ll x = qu.front().first, y = qu.front().second;
        qu.pop();
        for (auto &it : mv)
        {
            ll xn = x + it.first, yn = y + it.second;
            if (valid(xn, yn) and s[xn][yn] <= dest)
            {
                level[xn][yn] = level[x][y] + 1;
                qu.push({xn, yn});

                vis[xn][yn] = 1;

                if (s[xn][yn] == dest)
                {
                    ansx = xn, ansy = yn;
                    return level[xn][yn];
                }
            }
        }
    }
    return -1;
}
void solve(ll tc)
{
    cout << "Case " << tc << ": ";
    cin >> n;

    for (ll i = 0; i < n; i++)
        cin >> s[i];
    char mx = 'A';
    // ll x, y;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if(s[i][j]=='A')ansx=i, ansy=j;
            mx = max(mx, s[i][j]);
        }
    }
    // cout<<ansx<<" "<<ansy<<" "<<mx<<endl;
    ll ans=0;
    for(ll dest='B'; dest<=mx; dest++){
        memset(vis, 0, sizeof(vis));
        memset(level, 0, sizeof(level));
        ll val=bfs(ansx, ansy, dest);
        if(val==-1){
            cout<<"Impossible\n";
            return;
        }
        ans+=val;
    }
    cout << ans<< endl;
}
int main()
{
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
        solve(i);
}