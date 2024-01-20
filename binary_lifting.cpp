#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>parent(1<<20, -1);
vector<vector<ll>>dp(100000, vector<ll>(31));
int main(){
    parent[1]=1;
    parent[2]=1;
    parent[3]=1;
    parent[4]=parent[5]=2;
    for(ll i=1; i<5; i++){
        dp[i][0]=parent[i];
    }
    for(ll j=1; j<20; j++){
        for(ll v=0; v<5; v++){
            dp[v][j]=dp[dp[v][j-1]][j-1];
        }
    }
    for(int i=1; i<6; i++)cout<<dp[i][1]<<" ";
}