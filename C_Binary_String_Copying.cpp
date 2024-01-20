#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<pair<ll, ll>> v(q);
    for (ll i = 0; i < q; i++)
    {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        v[i] = {x, y};
    }
    set<pair<ll, ll>> st;
    ll zero[n + 2] = {0}, one[n + 2] = {0};
    zero[0] = -1;
    one[n - 1] = n;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '0')
            zero[i] = i;
        else if (i > 0)
            zero[i] = zero[i - 1];
    }
    for (ll i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1')
            one[i] = i;
        else if (i < n - 1)
            one[i] = one[i + 1];
    }
    for(auto &it: v){
        ll x=one[it.first], y=zero[it.second];
        if(x<=y)st.insert({x, y});
        else st.insert({INT64_MAX, INT64_MAX});
    }
    cout<<st.size()<<endl;
}
int main(){
    ll t;
    cin>>t;
    while(t--)solve();
}