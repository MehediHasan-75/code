#include<bits/stdc++.h>
using namespace std;
int main(){
    typedef long long ll;
    string s;
    cin>>s;

    stack<char>st;

    for(ll i=0; i<s.size(); i++){
        if(st.size() and st.top()==s[i])st.pop();
        else st.push(s[i]);
    }
    string ans="";
    while(st.size()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
}