#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

#define pi acos(-1.0)
double eps = 1e-12;
#define precision(n) cout << setprecision(n) << fixed;
typedef long double ld;

typedef long long ll;

vector<int>v, vclr;
void solve(ll tc)
{
    int k, n, ans = 0, need = 1;
    string s;

    cin >> n;
    n *= 2;

    while (n--)
    {
        cin >> s;
        if (s[0] == 'a')
        {
            cin >> k;
            v.push_back(k);
        }
        else
        {
            if (v.empty())
            {
            }
            else if (v.back() == need)
                v.pop_back();
            else
            {
                v = vclr;
                ans++;
            }
            need++;
        }
    }
    cout << ans << endl;
}
int main()
{
    fastio;ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

