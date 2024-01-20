#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll maximumSubarraySum(ll arr[], ll n)
{
    ll maxSum = INT_MIN;
    ll currSum = 0, prev=-1;

    for (ll i=0; i <n ; i++)
    {
        if(prev!=((arr[i]+10000000)%2))
        {
            currSum += arr[i];
        }
        else{
            currSum=arr[i];
        }
        if (currSum > maxSum)
        {
            maxSum = currSum;
        }
        if (currSum < 0)
        {
            currSum = 0;
        }
        prev=(arr[i]+10000000)%2;
    }

    return maxSum;
}
void solve(){
    ll n;
    cin>>n;

    ll arr[n];

    for(ll i=0; i<n; i++)cin>>arr[i];

    cout<<maximumSubarraySum(arr, n)<<endl;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)solve();
}
