#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define precision(n) cout << setprecision(n) << fixed;

const int N = 1000000;

pair<int, int> buildings[N];
ld phase[2][N];

ld angle(int a, int b)
{
  if (a == -1 or b == -1 or buildings[b].second <= buildings[a].second)
    return M_PI / 2.;
  return atan2(abs(buildings[a].first - buildings[b].first), buildings[b].second - buildings[a].second);
}

void hull(int n, ld *res)
{
  vector<int> all = {-1};
  for (int i = 0; i < n; i++)
  {
    while (all.size() >= 2 and angle(i, all[all.size() - 2]) <= angle(i, all.back()))
      all.pop_back();
    res[i] = angle(i, all.back());
    all.push_back(i);
  }
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> buildings[i].first >> buildings[i].second;
  for (int i = 2; i--;)
  {
    hull(n, phase[i]);
    reverse(buildings, buildings + n);
  }

  reverse(phase[0], phase[0] + n);
  precision(10);
  for (int i = 0; i < n; i++)
    cout << (phase[0][i] + phase[1][i]) * 12. / M_PI << endl;
}
