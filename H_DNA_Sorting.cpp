#include <bits/stdc++.h>
using namespace std;

int main()
{
    typedef long long ll;

    ll tc; cin >> tc;
    cin.ignore();

    for(ll i=1; i<=tc; i++)
    {
        if(i!=1)cout<<"\n";

        ll n, c;    cin >> c >> n;

        string str[n];
        for(ll i=0; i<n; i++)cin>>str[i];

        set<pair<ll, pair<ll,string>>>st;

        for (ll i=0; i<n; i++)
        {
            string cur_str=str[i];
            ll cnt = 0;
            for (ll i = 0; i < cur_str.size(); i++)
            {
                for (ll j = i + 1; j < cur_str.size(); j++)
                {
                    if (cur_str[i] > cur_str[j])
                        cnt++;
                }
            }
            // cout<<cnt<<" "<<cur_str<<endl;
            st.insert({cnt,{i,cur_str}});
        }
        for (auto &cur_str : st)
            cout<<cur_str.second.second<< "\n";
    }
}
