#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &it: v)cin>>it;
    vector<pair<int, int>>vp;
    for(int i=0; i<n; i++)vp.push_back({v[i], i});
    sort(vp.begin(), vp.end(), greater<pair<int, int>>());
    int ans=0;
    for(int i=0; i<n; i++){
        if(vp[i].second==i)continue;
        while(vp[i].second!=i){
             ans++;
             swap(vp[i], vp[vp[i].second]);
        }
    }
    cout<<ans<<endl;
}