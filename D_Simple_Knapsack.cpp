#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    ll n, w;
    cin >> n >> w;

    map<ll, vector<ll>> mp;
    for (ll i = 0; i < n; i++)
    {
        ll wt, v;
        cin >> wt >> v;
        mp[wt].push_back(v);
    }

    for (auto &it : mp)
        sort(it.second.begin(), it.second.end(), greater<ll>());
    for (auto &it : mp)
    {
        for (ll i = 1; i < it.second.size(); i++)
        {
            it.second[i] += it.second[i - 1];
        }
    }
    vector<ll> wt;
    for (auto &it : mp)
        wt.push_back(it.first);
    // cout<<wt.size()<<endl;
    ll ans = 0;
    if (wt.size() == 4)
    {
        for (ll i = 0; i <= mp[wt[0]].size(); i++)
        {
            for (ll j = 0; j <= mp[wt[1]].size(); j++)
            {
                for (ll k = 0; k <= mp[wt[2]].size(); k++)
                {
                    for (ll l = 0; l <= mp[wt[3]].size(); l++)
                    {
                        ll made = i * wt[0] + j * wt[1] + k * wt[2] + l * wt[3];
                        if (made > w)
                            continue;
                        ll sm = 0;
                        if (i - 1 >= 0)
                            sm += mp[wt[0]][i - 1];
                        if (j - 1 >= 0)
                            sm += mp[wt[1]][j - 1];
                        if (k - 1 >= 0)
                            sm += mp[wt[2]][k - 1];
                        if (l - 1 >= 0)
                            sm += mp[wt[3]][l - 1];
                        ans = max(ans, sm);
                    }
                }
            }
        }
    }
    if (wt.size() == 3)
    {
        for (ll i = 0; i <= mp[wt[0]].size(); i++)
        {
            for (ll j = 0; j <= mp[wt[1]].size(); j++)
            {
                for (ll k = 0; k <= mp[wt[2]].size(); k++)
                {
                    ll made = i * wt[0] + j * wt[1] + k * wt[2];
                    if (made > w)
                        continue;
                    ll sm = 0;
                    if (i - 1 >= 0)
                        sm += mp[wt[0]][i - 1];
                    if (j - 1 >= 0)
                        sm += mp[wt[1]][j - 1];
                    if (k - 1 >= 0)
                        sm += mp[wt[2]][k - 1];
                    ans = max(ans, sm);
                }
            }
        }
    }
    if (wt.size() == 2)
    {
        for (ll i = 0; i <= mp[wt[0]].size(); i++)
        {
            for (ll j = 0; j <= mp[wt[1]].size(); j++)
            {
                ll made = i * wt[0] + j * wt[1];
                if (made > w)
                    break;
                ll sm = 0;
                if (i - 1 >= 0)
                    sm += mp[wt[0]][i - 1];
                if (j - 1 >= 0)
                    sm += mp[wt[1]][j - 1];
                ans = max(ans, sm);
            }
        }
    }
    if (wt.size() == 1)
    {
        for (ll i = 0; i <= mp[wt[0]].size(); i++)
        {
            ll made = i * wt[0];
            if (made > w)
                break;
            if (i - 1 >= 0)
                ans = max(ans, mp[wt[0]][i - 1]);
        }
    }
    cout << ans << "\n";
}