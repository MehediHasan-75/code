#include<bits/stdc++.h>
using namespace std;
#define ll long long
multiset<char>st;
string s1, s2, ans="";
void func(ll ind, ll fl){
    if(ind==s2.size())return;
    if(fl==1){
        auto it=st.begin();
        while(*it<s2[ind])it++;
        if(ind+1<s2.size() and s2[ind+1]< *st.begin()) it--;
        ans+=*it;
        *it== s2[ind]? func(ind+1, 1): func(ind+1, 0);
        st.erase(it);
    }
    else{
        auto it=st.rbegin();
        ans+=*it;
        st.erase(--st.end());
        func(ind+1, 0);
    }
}
int main(){
    cin>>s1>>s2;
    for(auto &it: s1){
        st.insert(it);
    }
    func(0, 1);
}