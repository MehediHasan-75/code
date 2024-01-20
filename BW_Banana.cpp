#include<bits/stdc++.h>
using namespace std;
int main(){
    typedef long long ll;
    string s;
    cin>>s;
    ll n;
    cin>>n;

    map<char, ll>mp, cntt;

    for(auto &it: s)mp[it]++;
    set<pair<ll,char>>st;

    string ans="";
    for(auto &it: mp){
        st.insert({it.second--, it.first});
        ans+=it.first;
        cntt[it.first]++;
    }
    if(st.size()>n){
        cout<<"-1\n";
    }
    else{

        ll cnt=1;
        
        for(ll i=ans.size(); i<n; i++){
            auto it =st.end();
            it--;
            char ch=(*it).second;
            ll cnt=(*it).first-1;
            ans+=ch;
            cntt[ch]++;
            st.erase(it);
            st.insert({cnt, ch});
            mp[ch]--;
        }
        // cout<<ans<<endl;
        ll mx=0;

        for(auto &it: cntt){
            mx=max(mx, (mp[it.first]+it.second-1)/it.second);
        }
        cout<<cnt+mx<<endl;
        cout<<ans<<endl;
    }
}