#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string s;
    map<char, char>mp={{')', '('}, {']', '['}, {'>', '<'}, {'}', '{'}};
    while(cin>>s){
        stack<char>stk;
        bool fl=1;

        for(ll i=0; i<s.size(); i++){
            if(s[i]!=')' and s[i]!='}' and s[i]!='>' and s[i]!=']'){
                stk.push(s[i]);
            }
        }
    }
}