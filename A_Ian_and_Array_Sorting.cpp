#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    if (n & 1)
    {
        cout << "YES\n";
        return;
    }
    for (ll i = 1; i < n - 1; i++)
    {
        ll dif = v[i - 1] - v[i];
        v[i] += dif;
        v[i + 1] += dif;
    }
    cout << (v[n - 1] >= v[n - 2] ? "YES\n" : "NO\n");
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();
}