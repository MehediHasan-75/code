#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<set<ll>>v(26);
int main(){
    string s;
    cin>>s;
    for(ll i=0; i<s.size(); i++)v[s[i]-'a'].insert(i);
    ll q;
    cin>>q;
    while(q--){
        ll type;
        cin>>type;
        if(type==1){
            ll ind;
            char ch;
            cin>>ind>>ch;
            ind--;
            v[s[ind]-'a'].erase(ind);
            s[ind]=ch;
            v[s[ind]-'a'].insert(ind);
        }
        else{
            ll l, r;
            cin>>l>>r;
            l--, r--;
            ll cnt=0;
            for(ll i=0; i<26; i++){
                auto it=v[i].lower_bound(l);
                if(it!=v[i].end() and *it<=r)cnt++;
            }
            cout<<cnt<<endl;
        }
    }
}