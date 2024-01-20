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
    vector<bool> vis(n, false);
    // Traverse array elements
    for (int i = 0; i < n; i++) {
        // already swapped and corrected or
        // already present at correct pos
        if (vis[i] || vp[i].second == i)
            continue;
 
        // find out the number of  node in
        // this cycle and add in ans
        int cycle_size = 0;
        int j = i;
        while (!vis[j]) {
            vis[j] = 1;
 
            // move to next node
            j = vp[j].second;
            cycle_size++;
        }
 
        // Update answer by adding current cycle.
        if (cycle_size > 0) {
            ans += (cycle_size - 1);
        }
    }
    cout<<ans<<endl;
}