#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll dp[201][201][201];
ll func(ll r, ll g, ll b){
    if(r+g+b==1){
        if(r==1)return 1;
        if(g==1)return 2;
        if(b==1)return 4;
    }
    if(dp[r][g][b]!=-1)return dp[r][g][b];
    ll ans=0;
    if(r>=1  and b>=1 ){
        ans|=func(r-1, g+1, b-1);
    }
    if(r>=1 and g>=1){
        ans|=func(r-1, g-1, b+1);
    }
    if(g>=1  and b>=1){
        ans|=func(r+1, g-1, b-1);
    }
    if(r>1){
        ans|=func(r-1, g, b);
    }
    if(b>1){
        ans|=func(r, g, b-1);
    }
    if(g>1){
        ans|=func(r, g-1, b);
    }
    return dp[r][g][b]=ans;
}
int main(){
    ll n;
    cin>>n>>s;
    ll r=0, g=0, b=0;
    for(ll i=0; i<n; i++){
        if(s[i]=='R')r++;
        else if(s[i]=='G')g++;
        else b++;
    }
    memset(dp, -1, sizeof(dp));
    ll ans=func(r, g, b);
    if(ans==1)cout<<'R'<<endl;
    else if(ans==2)cout<<'G'<<endl;
    else if(ans==4)cout<<'B'<<endl;
    else if(ans==3)cout<<"GR\n";
    else if(ans==5)cout<<"BR\n";
    else if(ans==6)cout<<"BG\n";
    else cout<<"BGR\n";
}