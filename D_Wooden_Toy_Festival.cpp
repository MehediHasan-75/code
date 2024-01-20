#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >>t;

    while (t--)
    {
        ll n;
        cin >> n;
        vector<int> v(n);
        for (ll i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        ll lo = 0;
        ll hi = 1e9 + 5;
        ll mid, ans = 0;
        while (lo <= hi)
        {
            mid = (lo+hi)>>1;
            ll k, l = 0, cnt = 0;
            for (k = 0; k < n; k++)
            {
                if (v[k] - v[l] > 2 * mid)
                {
                    l = k;
                    cnt++;
                }
            }
            if (cnt >= 3)
            {
                lo = mid + 1;
            }
            else
            {
                ans = mid, hi = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}