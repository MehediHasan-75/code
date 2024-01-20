#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string s;
    cin>>s;

    stack<char>st;

    for(ll i=0; i<s.size(); i++){
        st.push(s[i]);

        while(st.size()>=3){
            char c=st.top()[1];
            st.pop();
            char b=st.top();
            st.pop();
            char a=st.top();
            st.pop();

            if(a=='A' and b=='B' and c=='C')continue;
            else{
                st.push(a);
                st.push(b);
                st.push(c);
                break;
            }
        }
    }
    string stt="";
    while(st.size())
    {
        stt+=st.top();
        st.pop();
    }
    reverse(stt.begin(),stt.end());
    cout<<stt<<endl;
}