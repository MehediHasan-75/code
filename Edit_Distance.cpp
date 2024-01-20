#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[5000][5000];
ll func(string &s1, string &s2, ll ind1, ll ind2){
    
    if(ind1==s1.size())return s2.size()-ind2;
    else if(s2.size()==ind2) return s1.size()- ind1;
    ll ans=0;
    if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
    if(s1[ind1]==s2[ind2])ans=func(s1, s2, ind1+1, ind2+1);
    else ans = 1+ min({func(s1, s2, ind1+1, ind2), func(s1, s2, ind1, ind2+1), func(s1, s2, ind1+1, ind2+1)});
    return dp[ind1][ind2]=ans;
}
int main(){
    string s1, s2;
    cin>>s1>>s2;
    memset(dp, -1, sizeof(dp));
    cout<<func(s1, s2, 0, 0)<<endl;
}