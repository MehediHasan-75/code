#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s1, s2;
#define N 3001
ll dp[N][N];
ll path[N][N];
ll func(ll ind1,ll ind2){
    
    if(ind1==s1.size() or ind2==s2.size()){
        return 0;
    }
    if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
    if(s1[ind1]==s2[ind2]){
        path[ind1][ind2]=1;
        return dp[ind1][ind2]=1+func(ind1+1, ind2+1);
    }
    else{
        ll l=func(ind1, ind2+1);
        ll r=func(ind1+1, ind2);
        if(l>=r)path[ind1][ind2]=2;
        else path[ind1][ind2]=3;
        return dp[ind1][ind2]=max(l, r);
    }
}
void find_path(ll ind1, ll ind2){
    if(ind1==s1.size() or ind2==s2.size()){
        return;
    }
    if(path[ind1][ind2]==1){
        cout<<s1[ind1];
        find_path(ind1+1, ind2+1);
    }
    else if(path[ind1][ind2]==2)find_path(ind1, ind2+1);
    else find_path(ind1+1, ind2);
}
int main(){
    cin>>s1>>s2;
    memset(dp, -1, sizeof(dp));
    func(0, 0);
    find_path(0,0);
}