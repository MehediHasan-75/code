
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(ll tc)
{
    string s1, s2;
    cin >> s1 >> s2;

    // cout<<s1<<" "<<s2<<endl;
    ll n = s1.size(), problem_cnt = 0;
    s1 = "#" + s1;
    s2 = "#" + s2;
    // cout<<n<<" "<<s1.size()<<endl;
    vector<ll> problem(n + 5, 0);
    queue<pair<ll, ll>> blocked;
    for (ll i = 1; i <= n; i++)
    {
        if (s1[i] != s2[i])
        {
            problem_cnt++;
            problem[i] = 1;
        }
    }
    ll q, t;
    cin >> t >> q;
    // cout<<"q = "<<q<<" t= "<<t<<endl;
    for (ll i = 1; i <= q; i++)
    {
        while (!blocked.empty())
        {
            if (i - (blocked.front().second) >= t)
            {
                blocked.pop();
                problem_cnt++;
            }
            else
                break;
        }
        ll type;
        cin >> type;
        if (type == 1)
        {
            ll ind;
            cin >> ind;
            if (problem[ind])
            {
                blocked.push({ind, i});
                problem_cnt--;
            }
        }
        else if (type == 3)
        {
            if (problem_cnt == 0)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
        {
            ll x, ind1, y, ind2;
            cin >> x >> ind1 >> y >> ind2;

            if (x == 1 and y == 1)
            {
                swap(s1[ind1], s1[ind2]);
            }
            else if (x == 2 and y == 2)
            {
                swap(s2[ind1], s2[ind2]);
            }
            else if (x = 1 and y == 2)
            {
                swap(s1[ind1], s2[ind2]);
            }
            else
            {
                swap(s2[ind1], s1[ind2]);
            }
            if (problem[ind1])
            {
                problem_cnt--;
            }
            if (problem[ind2])
            {
                problem_cnt--;
            }
            problem[ind1] = problem[ind2] = 0;
            if (s1[ind1] != s2[ind1])
            {
                problem[ind1] = 1;
                problem_cnt++;
            }
            if (s1[ind2] != s2[ind2])
            {
                problem[ind2] = 1;
                problem_cnt++;
            }
        }
    }
}
int main()
{
    ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)
        solve(i);
    return 0;
}
