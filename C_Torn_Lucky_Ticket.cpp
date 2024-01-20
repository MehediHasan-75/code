
#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
   ios_base::sync_with_stdio(false); \
   cin.tie(NULL);                    \
   cout.tie(NULL);

#define prnt(x)          \
   for (auto &it : x)    \
      cout << it << " "; \
   cout << "\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 2e5 + 10, inf = 2e18;
ll mod = 1000000007;

ll sum(string s)
{
   ll sum = 0;
   for (ll i = 0; i < s.size(); i++)
      sum += s[i] - '0';
   return sum;
}

void solve(ll tc)
{
   ll n;
   cin >> n;
   vector<string> v(n);

   ll dp[10][50] = {0};
   for (ll i = 0; i < n; i++)
   {
      cin >> v[i];
      dp[v[i].size()][sum(v[i])]++;
      // cout<<dp[v[i].size()][sum(v[i])]<<" "<<v[i]<<endl;
   }

   ll ans = 0;
   for (ll i = 0; i < n; i++)
   {
      string s = v[i];
      ll len = v[i].size(), sm = sum(s);

      ans += dp[len][sum(s)];

      ll removedSum = 0, r = 0;
      for (int i = 0; i < len - 1; i++)
      {
         removedSum += (s[i] - '0');
         r++;

         ll right = len - r;
         ll rightSum = sm - removedSum;

         ll remainingLeft = right - r;
         ll remainingLeftSum = rightSum - removedSum;

         if (remainingLeftSum >= 0 && remainingLeft >= 0 && ((right + remainingLeft + r) % 2 == 0))
            ans += dp[remainingLeft][remainingLeftSum];
      }
      removedSum = 0, r = 0;
      for (ll i = len - 1; i > 0; i--)
      {
         removedSum += (s[i] - '0');
         r++;

         ll left = len - r;
         ll leftSum = sm - removedSum;

         ll remainingRight = left - r;
         ll remainingRightSum = leftSum - removedSum;

         if (remainingRight >= 0 && remainingRightSum >= 0 && ((left + remainingRight + r) % 2 == 0))
            ans += dp[remainingRight][remainingRightSum];
      }
   }
   cout << ans << endl;
}
int main()
{
   fastio;
   ll T = 1;
   // cin >> T;
   for (ll i = 1; i <= T; i++)
      solve(i);
   return 0;
}
