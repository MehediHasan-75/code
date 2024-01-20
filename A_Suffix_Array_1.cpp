#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
void radixSort(vector<pair<pair<ll, ll>, ll>> &v)
{
    ll n = v.size();
    {
        vector<ll> cnt(n, 0), st_bucket(n);

        vector<pair<pair<ll, ll>, ll>> new_v(n);

        for (auto &it : v)
        {
            cnt[it.first.second]++;
        }
        st_bucket[0] = 0;
        for (ll i = 1; i < n; i++)
        {
            st_bucket[i] = st_bucket[i - 1] + cnt[i - 1];
        }
        for (auto &it : v)
        {
            ll x = it.first.second;
            new_v[st_bucket[x]] = it;
            st_bucket[x]++;
        }
        v = new_v;
    }

    {
        vector<ll> cnt(n, 0), st_bucket(n);

        vector<pair<pair<ll, ll>, ll>> new_v(n);

        for (auto &it : v)
        {
            cnt[it.first.first]++;
        }
        st_bucket[0] = 0;
        for (ll i = 1; i < n; i++)
        {
            st_bucket[i] = st_bucket[i - 1] + cnt[i - 1];
        }
        for (auto &it : v)
        {
            ll x = it.first.first;
            new_v[st_bucket[x]] = it;
            st_bucket[x]++;
        }
        v = new_v;
    }
}
void suffixArray()
{
    string s;
    cin >> s;

    s += "$";// making sting as circular to avoid runtime error($ is samller than any alphabet so no problem)
    // cout<<s<<endl;

    ll n = s.size();// size of string with $ sign
    vector<ll> number(n), array(n);
    //number will store value given to corresponding segemet(starting index)
    //arry will store suffix arry(sorted suffix's starting positions)
    vector<pair<char, ll>> v;
    for (ll i = 0; i < n; i++)
        v.push_back({s[i], i});

    sort(v.begin(), v.end());
    for (ll i = 0; i < n; i++)
        array[i] = v[i].second;

    number[array[0]] = 0;
    for (ll i = 1; i < n; i++)
    {
        if (v[i - 1].first == v[i].first)
            number[array[i]] = number[array[i - 1]];
        else
            number[array[i]] = number[array[i - 1]] + 1;
    }
    ll k = 0;
    while ((1ll << k) < n)
    {
        vector<pair<pair<ll, ll>, ll>> v(n);
        for (ll i = 0; i < n; i++)
        {
            v[i] = {{number[i], number[(i + (1ll << k)) % n]}, i};
        }
        radixSort(v);
        for (ll i = 0; i < n; i++)
            array[i] = v[i].second;
        number[array[0]] = 0;
        for (ll i = 1; i < n; i++)
        {
            if (v[i - 1].first == v[i].first)
                number[array[i]] = number[array[i - 1]];
            else
                number[array[i]] = number[array[i - 1]] + 1;
        }
        k++;
    }
    for (ll i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
int main()
{
    fastio;
    suffixArray();
}