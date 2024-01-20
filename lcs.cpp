#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll func(string &s1, string &s2, ll ind1, ll ind2){
    if(ind1>=s1.size()  or ind2>=s2.size())return 0;
    if(s1[ind1]==s1[ind2])return 1+func(s1, s2, ind1+1, ind2+1);
    return func(s1, s2, ind1+1, ind2)+func(s1, s2, ind1, ind2+1);
}
int main(){
    string s1, s2;
    cin>>s1>>s2;
    ll lc=func(s1, s2, 0, 0);
    cout<<lc<<endl;
}