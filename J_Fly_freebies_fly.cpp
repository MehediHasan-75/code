#include<bits/stdc++.h>
using namespace std;
int main(){
    typedef long long ll;
    ll n;
    cin>>n;

    vector<ll>v(n);

    for(auto &it: v)cin>>it;


    ll interval;
    cin>>interval;

    sort(v.begin(), v.end());

    ll lo=0, hi=0, mx=0;

    for(; hi<n; hi++){
        while(v[hi]-v[lo]>interval)lo++;
        mx=max(mx, hi-lo+1);
    }
    cout<<mx<<endl;
}