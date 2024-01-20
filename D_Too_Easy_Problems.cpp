#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, t;
bool chk(ll need, vector<pair<pair<ll, ll>, ll>> &v)
{
    ll can = 0, time_taken = 0;
    // cout<<need<<endl;
    for (ll i = 0; i <= v.size(); i++)
    {
        if (can == need)
            break;
        if (v[i].first.second >= need){
            can++, time_taken += v[i].first.first ;
            // cout<<can<<" "<<time_taken<<" "<<v[i].first.second<<endl;
        }
       
    }
    return can == need and time_taken <= t;
}
int main()
{
    cin >> n >> t;
    vector<pair<pair<ll, ll>, ll>> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].first.second >> v[i].first.first;
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end());
    ll hi = n, lo = 0, ans = 0;
    while (hi >= lo)
    {
        ll mid = (hi + lo) / 2;
        if (chk(mid, v))
        {
            lo = mid + 1;
            ans = mid;
        }
        else
            hi = mid - 1;
    }
    cout << ans << endl;
    cout<<ans<<endl;
    ll can = 0, time_taken = 0;
    // cout<<need<<endl;
    for (ll i = 0; i <= v.size(); i++)
    {
        if (can == ans)
            break;
        if (v[i].first.second >= ans){
            can++, cout<<v[i].second <<" ";
            // cout<<can<<" "<<time_taken<<" "<<v[i].first.second<<endl;
        }
       
    } 
    cout<<endl; 
}