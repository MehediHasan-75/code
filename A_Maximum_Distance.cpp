
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll N = 2e5 + 10, inf = 2e18;
ll mod = 1000000007;
void solve(ll tc)
{
    ll n, m;
    cin >> n;

    vector<ll> a(n), b(n);
    for(auto &it: a)cin>>it;
    for(auto &it: b)cin>>it;
    
    ll mx = 0, lp = 2;
    while (lp--)
    {
        for (ll i = 0; i < n; i++)
        {
            ll ind = 0, cnt = 0;
            for (ll j = i; j < n; j++)
            {
                if (a[ind++] != b[j])
                    cnt++;
            }
            mx = max(cnt, mx);
        }
        swap(a, b);
    }
    cout<<mx<<endl;
}
int main()
{
    ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)
        solve(i);
    return 0;
}
