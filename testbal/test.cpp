#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5 + 10;

vector<ll> graph1[N], graph2[N];
ll indegree1[N], indegree2[N];
queue<ll> qu1[3], qu2[3];
ll type[N];

int main()
{
    freopen("jediacademy.in", "r", stdin);
    freopen("jediacademy.out", "w", stdout);
    ll n, a, b;
    cin >> n;
    for (int v = 1; v <= n; v++)
    {
        int k;
        cin >> type[v] >> k;
        if (k == 0)
        {
            qu1[type[v]].push(v);
            qu2[type[v]].push(v);
        }
        else
        {
            for (int j = 0; j < k; ++j)
            {
                int u;
                cin >> u;
                graph1[u].push_back(v);
                graph2[u].push_back(v);
                indegree1[v]++;
                indegree2[v]++;
            }
        }
    }
    cin >> a >> b;
    ll ans = INT64_MAX, skill = 0, building = 1, temp_ans = a;
    while (skill < n)
    {
        if (qu1[building].empty())
        {

            building = 3 - building;
            temp_ans += b;
            if (qu1[building].empty())
                break;
            temp_ans += a;
            ll v = qu1[building].front();
            qu1[building].pop();
            for (auto u : graph1[v])
            {
                indegree1[u]--;
                if (!indegree1[u])
                    qu1[type[u]].push(u);
            }
        }
        else
        {
            temp_ans += b;
            ll v = qu1[building].front();
            qu1[building].pop();
            for (auto u : graph1[v])
            {
                indegree1[u]--;
                if (!indegree1[u])
                    qu1[type[u]].push(u);
            }
        }
        skill++;
    }
    ans = min(temp_ans, ans);

    skill = 0;

    building = 2;
    temp_ans = a;
    while (skill < n)
    {
        if (qu2[building].empty())
        {

            building = 3 - building;
            temp_ans += b;
            if (qu2[building].empty())
                break;
            temp_ans += a;
            ll v = qu2[building].front();
            qu2[building].pop();
            for (auto u : graph2[v])
            {
                indegree2[u]--;
                if (!indegree2[u])
                    qu2[type[u]].push(u);
            }
        }
        else
        {
            temp_ans += b;
            ll v = qu2[building].front();
            qu2[building].pop();
            for (auto u : graph2[v])
            {
                indegree2[u]--;
                if (!indegree2[u])
                    qu2[type[u]].push(u);
            }
        }
        skill++;
    }
    ans = min(temp_ans, ans);
    cout << ans << "\n";
    return 0;
}
