#include<bits/stdc++.h>
using namespace std;
#define int long long int 

int32_t main()
{
    int p;
    cin >> p;

    vector<int>v(p,-1);
    v[0] = 0;
    for(int i = 1 ; i < p ; i ++){
        int cur = (i*i) % p;
        v[cur] = i;
    }

    for(auto i : v) cout<<i<<" ";

}