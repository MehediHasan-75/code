#include<bits/stdc++.h>
using namespace std;
const int N=100;
#define ll long long

vector<ll>v(N);
ll n;
/*
	

A sequence of numbers is called a zig-zag sequence if the differences between successive numbers strictly alternate between positive and negative. 
Given a sequence of integers, sequence, return the length of the longest subsequence of sequence that is a zig-zag sequence. */
// ll solve(ll ind , ll prev_sign){
//     if(ind==n)return 0;

//     ll mx=0;

//     for(ll i=ind+1; i<n; i++){
//         if( ( (v[ind]-v[i])<0 and prev_sign>0 ) or (v[ind]-v[i]>0 and prev_sign<0)){
//             mx=max(mx, 1+solve(i, v[ind]-v[i]));
//         }
//     }
//     return mx;
// }

int main(){
    cin>>n;

    for(ll i=0; i<n; i++)cin>>v[i];


    /*
	A sequence of numbers is called a zig-zag sequence if the differences between successive numbers strictly alternate between positive and negative. 
    Given a sequence of integers, sequence, return the length of the longest subsequence of sequence that is a zig-zag sequence.
    */
    // vector<ll>dp(n, 1), sinn(n, -1);// -1 means start, 0 means found positive, 1 means found negative.
    // for(ll i=1; i<n; i++){
    //     for(ll j=0; j<i; j++){
    //         if( (sinn[j]==-1 or sinn[j]==0) and (v[i]-v[j]<0)){
    //             if(dp[i]<dp[j]+1){
    //                 dp[i] = dp[j]+1;
    //                 sinn[i]=1;
    //             }
    //         }
    //         else if( (sinn[j]==-1 or sinn[j]==1) and (v[i]-v[j]>0)){
    //             if(dp[i]<dp[j]+1){
    //                 dp[i] = dp[j]+1;
    //                 sinn[i]=0;
    //             }
    //         }
    //     }
    // }
    // ll mx=0;
    // for(ll i=0; i<n; i++){
    //     mx=max(dp[i], mx);
    // }
    // cout<<mx<<endl;

    // cout<<max(solve(0, -1), solve(0, 1))+1<<endl;

    /*longest common subsequence*/
    //vector<ll>dp(n, 1);
    // for(ll i=0; i<n; i++){// dp[i]= longest increasing subsequence ending at index i.

    //     for(ll j=0; j<i; j++){
    //         if(v[i]>=v[j]){// as j is always less than i . answer for v[j] is already ready. so we only need to check v[j] and if v[j] is valid then answer caluclate for v[j] is also valid.
    //             dp[i]=max(dp[i], dp[j]+1);
    //         }
    //     }
    // }
    // ll mx=1;

    // for(ll i=0; i<n; i++)mx=max(mx, dp[i]);

    // cout<<mx<<endl;



}