#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &it : v)
        cin >> it;
    reverse(v.begin(), v.end());
    vector<ll> ans;
    for (ll i = 0; i < n;)
    {
        ll cntZero = 0, cntOne = 0;
        while (i < n and v[i] == 0)
        {
            cntZero++;
            ans.push_back(0);
            i++;
        }
        while (i < n and v[i] == 1)
        {
            cntOne++;
            if (cntZero == 0)
            {
                cout << "NO\n";
                return;
            }
            ans.push_back(0);
            i++;
        }
        if (cntOne > 0)
        {
            ans.pop_back();
            ans.push_back(cntOne);
        }
    }
    cout << "YES\n";
    for (auto &it : ans)
        cout << it << " ";
    cout << endl;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();
}