/*Interval can be uniquely represented as a union of intervals with lengths that are decreasing powers of two
as any non-negative number can be uniquely represented as a sum of decreasing powers of two*/
const int LOG = 31;
ll stable[LOG][N];
/*stable[i][j]= range[i][j, j+2^i-1];
 */
ll func(ll a, ll b)
{
    return min(a, b);
}
ll rangeMinQuery(ll l, ll r)
{
    ll len = r - l + 1, i = log2(len);
    // cout<<i<<endl;
    return min(stable[i][l], stable[i][r - (1 << i) + 1]);
}
ll rangeQuery(ll l, ll r)
{
    ll sum = 0;
    for (int i = LOG; i >= 0; i--)
    {
        if ((1 << i) <= r - l + 1)
        {
            sum += stable[i][l];
            l += 1 << i;
        }
    }
    return sum;
}
void spharseTable(vector<ll> &array)
{
    copy(array.begin(), array.end(), stable[0]); // storing information of stable[i][0] means original array
    for (ll i = 1; i < LOG; i++)
    {
        for (ll j = 0; j + (1ll << i) < N; j++)
        {
            stable[i][j] = func(stable[i - 1][j], stable[i - 1][j + (1 << (i - 1))]);
        }
    }
}
#include<bits/stdc++.h>
using namespace std;
const int LOG=21, N=3e5+10;
#define ll long long
#define endl "\n"
vector<ll>v(N);
ll stablegc[LOG][N], n;

ll get_ans(ll l, ll r){
    ll len = r - l + 1, i = log2(len);
    // cout<<i<<endl;
    return __gcd(stablegc[i][l], stablegc[i][r - (1 << i) + 1]);   
}
