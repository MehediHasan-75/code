#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1e9 + 7;
bool ans;

vector<pair<int, int>> mv = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
map<vector<vector<int>>, bool> mp;
stack<vector<vector<int>>> st;

vector<vector<int>> last = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

bool isvalid(int x, int y)
{
    return x > -1 && x < 3 && y > -1 && y < 3;
}

void dfs(vector<vector<int>> &vec)
{
    if (ans)
        return;
    if (vec == last)
    {
        st.push(last);
        ans = true;
        return;
    }
    if (mp[vec])
        return;
    mp[vec] = true;
    int xi, xj;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (vec[i][j] == 0)
            {
                xi = i;
                xj = j;
            }
        }
    }
    for (int i = 0; i < mv.size(); i++)
    {
        if (isvalid(xi + mv[i].first, xj + mv[i].second))
        {
            swap(vec[xi][xj], vec[xi + mv[i].first][xj + mv[i].second]);
            dfs(vec);
            swap(vec[xi][xj], vec[xi + mv[i].first][xj + mv[i].second]);
            if (ans)
            {
                st.push(vec);
                return;
            }
        }
    }
}

signed main()
{
    // freopen("","r+",stdin);
    // freopen("","w+",stdout);
    FastIO;
    int t = 1;
    // cin>>t;
    for (int z = 1; z <= t; z++)
    {
        ans = false;
        vector<vector<int>> vec;
        // vector<int>vec[3];
        for (int i = 0; i < 3; i++)
        {
            vector<int> tem;
            for (int j = 0; j < 3; j++)
            {
                int a;
                cin >> a;
                tem.pb(a);
            }
            vec.pb(tem);
        }
        dfs(vec);
        while (st.size())
        {
            vector<vector<int>> tem = st.top();
            st.pop();
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << tem[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}