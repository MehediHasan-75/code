#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define Mx 8000001

int k1, k2, dp[Mx];
pair<pair<int, int>, int> element1[Mx];pair<pair<int, int>, pair<int, int>> element2[Mx];
set<int> st1;
set<pair<int, int>> st2;set<int>::iterator iterator1;
set<pair<int, int>>::iterator iterator2, iterator22;

const int inf = (int)1e9;
bool input(int &x)
{
	char c, r = 0, n = 0;
	x = 0;
	for (;;)
	{
		c = getchar();
		if ((c < 0) && (!r))
			return (0);
		if ((c == '-') && (!r))
			n = 1;
		else if ((c >= '0') && (c <= '9'))
			x = x * 10 + c - '0', r = 1;
		else if (r)
			break;
	}
	if (n)
		x = -x;
	return (1);
}

void adds(int x1, int y1, int x2, int y2)
{
	if ((x2 < 0) || (y1 > inf))
		return;
	int i = k2 + 1;
	element2[k2++] = make_pair(make_pair(y1, 1), make_pair(x1, i));
	element2[k2++] = make_pair(make_pair(y2, 0), make_pair(x2, i));
}

void addss(int x)
{
	int i;
	int X[7];
	iterator1 = st1.lower_bound(x);
	for (i = 0; i < 3; i++)
		iterator1--;
	for (i = 0; i < 7; i++)
		X[i] = *iterator1, iterator1++;
	for (i = 0; i < 4; i++)
		adds(X[i], X[i + 1], X[i + 2], X[i + 3]);
}

int question(int x)
{
	auto it = st2.lower_bound(make_pair(x + 1, 0));
	it--;
	return (it->second);
}

void updt(int x, int v)
{
	auto it = st2.lower_bound(make_pair(x + 1, 0));
	it--;
	if (v <= it->second)
		return;
	if (it->first < x)
		it++;
	while ((it != st2.end()) && (v >= it->second))
	{
		iterator22 = it, it++;
		st2.erase(iterator22);
	}
	st2.insert(make_pair(x, v));
}

int main()
{
	freopen("C:\\Users\\Mehedi\\Desktop\\t1.txt", "r", stdin);
	freopen("C:\\Users\\Mehedi\\Desktop\\t1.txt", "w", stdout);
	int T, t;
	int N;
	int i, j, k, x, a, b, ans;

	input(T);
	for (t = 1; t <= T; t++)
	{
		input(N);
		k1 = 0;
		for (i = 0; i < N; i++)
		{
			input(x), input(a), input(b);
			element1[k1++] = make_pair(make_pair(a, x), 1);
			element1[k1++] = make_pair(make_pair(b + 1, x), -1);
		}
		sort(element1, element1 + k1);
		st1.clear();
		for (int i = 1; i <= 4; i++)
			st1.insert(-i), st1.insert(inf + i);
		k2 = 0;
		for (i = 0; i < k1; i++)
		{
			j = i;
			while ((j + 1 < k1) && (element1[j + 1].first.first == element1[i].first.first))
				j++;
			for (k = i; k <= j; k++)
				if (element1[k].second > 0)
					st1.insert(element1[k].first.second);
				else
					st1.erase(element1[k].first.second);
			for (k = i; k <= j; k++)
				addss(element1[k].first.second);
			i = j;
		}
		sort(element2, element2 + k2);
		st2.clear();
		st2.insert(make_pair(-inf, 0));
		ans = 0;
		for (i = 0; i < k2; i++)
		{
			x = element2[i].second.first, j = element2[i].second.second;
			if (element2[i].first.second)
				Max(ans, dp[j] = question(x) + 1);
			else
				updt(x, dp[j]);
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return (0);
}