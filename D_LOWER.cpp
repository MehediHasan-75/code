// #pragma GCC target("fpmath=sse,sse2") // off
// #pragma GCC target("fpmath=387") // on
// #pragma GCC optimize("unroll-loops,O3")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#include <ext/random>
#ifdef DEBUG
#include <sys/resource.h>
#endif
#define int long long
using namespace __gnu_pbds;
const int mod = 1e9 + 7;
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define FORr(i, a, b) for (int i = a; i >= (int)b; i--)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, n)
#define print(arr)        \
    for (auto a : arr)    \
        cout << a << " "; \
    cout << endl;
#define in(a) \
    int a;    \
    cin >> a;
#define inp(arr, n)     \
    vector<int> arr(n); \
    for (auto &a : arr) \
        cin >> a;
#define pb emplace_back
#define all(a) a.begin(), a.end()
#define mp make_pair
#define f first
#define vi vector<int>
#define s second
#define mxheap priority_queue<int>
#define mnheap priority_queue<int, vector<int>, greater<int>>
#define mxheap2 priority_queue<pair<int, int>>
#define mnheap2 priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define case cout << "Case " << tt << ": ";
inline int uceil(int a, int b)
{
    int res = a / b;
    if (a % b and res >= 0)
        res++;
    return res;
}
#define pll pair<int, int>
#define set_bit(x, idx) x = x | (1LL << idx)
int dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[8] = {-1, 0, 1, 0, 1, 1, -1, -1};
#define toggle_bit(x, idx) x = x ^ (1LL << idx)
#define check_bit(x, idx) min(x & (1LL << idx), 1LL)
#define sz(x) (int)x.size()
#define endl "\n"
#define yes cout << "Yes\n";
#define no cout << "No\n";
#define db long double
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x, y) uniform_int_distribution<int>(x, y)(rng)
#define CAST(X) std::bitset<sizeof(X) * 8>
#define ACCESS(X) ((std::bitset<sizeof(X) * 8>)&X)

#ifdef DEBUG
#include "tpc.hpp"
#define pause(x) thamm(x)
#define FAST_IO
#define dbg(...)                          \
    {                                     \
        cerr << _LINE_ << ": ";           \
        dbg_out(#__VA_ARGS__, _VA_ARGS_); \
    }
#define ok tikkk
#elif ASHIQ
#define pause(x)
#define FAST_IO
#define dbg(...)
#define ok
#else
#define pause(x)
#define FAST_IO                           \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(0);                       \
    }
#define dbg(...)
#define ok
#endif

// aboid function
void solvetc(int tt)
{
    in(n)
        string one;
    cin >> one;
    set<int> upperCase, lowerCase;
    for (int i = 0; i < n; i++)
    {
        if (isupper(one[i]))
            upperCase.insert(i);
        else
            lowerCase.insert(i);
    }
    in(q)
        rep(i, q)
    {
        in(t)in(x) char m;
        cin >> m;
        if (t == 1)
        {
            if (upperCase.find(x - 1) != upperCase.end())
            {
                upperCase.erase(x - 1);
            }
            else
            {
                lowerCase.erase(x - 1);
            }
            one[x - 1] = m;
            if (isupper(m))
                upperCase.insert(x - 1);
            else
                lowerCase.insert(x - 1);
        }
        else if (t == 2)
        {
            if (upperCase.size() > lowerCase.size())
            {
                upperCase.insert(all(lowerCase));
                lowerCase.clear();
                swap(upperCase, lowerCase);
            }
            else
            {
                lowerCase.insert(all(upperCase));
                upperCase.clear();
            }
        }
        else
        {
            if (lowerCase.size() > upperCase.size())
            {
                lowerCase.insert(all(upperCase));
                upperCase.clear();
                swap(upperCase, lowerCase);
            }
            else
            {
                upperCase.insert(all(lowerCase));
                lowerCase.clear();
            }
        }
    }
    for (auto x : upperCase)
    {
        one[x] = toupper(one[x]);
    }
    for (auto x : lowerCase)
    {
        one[x] = tolower(one[x]);
    }
    cout << one << endl;
}

int32_t main()
{
    FAST_IO;
#ifdef DEBUG
    init_mem;
// freopen("in", "r", stdin);
#endif
    int nn = 1;
    // cin >> nn;
    rep(i, nn) solvetc(i + 1);
#ifdef DEBUG
    show_mem;
#endif
}