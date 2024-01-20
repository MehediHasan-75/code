#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
template <typename T>
using order_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
;
// kthElement = *myTree.find_by_order(1), index(zero based) = myTree.order_of_key(8);
vector<pair<string, string>>query[500000];
int main()
{
    ll n;
    cin >> n;

    string person, city;
    ll balance;

    map<string, string> mpperson;
    map<string, ll> mpcity, pbalance;
    for (ll i = 0; i < n; i++)
    {
        cin >> person >> city >> balance;
        mpcity[city] += balance;
        mpperson[person] = city;
        pbalance[person] = balance;
    }
    ll m, k;
    cin >> m >> k;

    map<string, ll> ans;
    order_set<pair<ll, string>> st;

    for (auto &it : mpcity)
    {
        st.insert({-it.second, it.first});
    }

    for (ll i = 0; i < k; i++)
    {
        ll day;
        string player, city;
        cin >> day >> player >> city;

        query[day].push_back({player, city});
    }

    for (ll i=1; i<=m; i++)
    {

        for (auto tt : query[i-1])
        {
            string player=tt.first, city=tt.second;
            string prev = mpperson[player];

            auto it1 = st.find({-mpcity[prev], prev});
            st.erase(it1);
            mpcity[prev] -= pbalance[player];
            st.insert({-mpcity[prev], prev});

            auto it2 = st.find({-mpcity[city], city});
            if (it2 != st.end())
            {
                st.erase(it2);
            }
            mpcity[city] += pbalance[player];
            st.insert({-mpcity[city], city});

            mpperson[player] = city;
        }
        if(st.size()==1){
            ans[st.begin()->second]++;
           
        }
        else{
            auto it=st.begin();
            auto p=(*it);
            it++;
            auto p1=(*it);
            if(p.first<p1.first)ans[p.second]++;
            //  cout<<"hi\n";
        }
    }
    for (auto &it : ans)
    {
        cout << it.first << " " << it.second << endl;
    }
}