#include<bits/stdc++.h>
using namespace std;
int main(){
    typedef long long ll;
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    ll n;
    cin>>n;
    // cout<<n<<endl;
    vector<ll>v(n);
    for(auto &it: v)cin>>it;

    sort(v.begin(), v.end());

    ll i=0, j=0, ans=INT64_MAX;

    for(; i<n; i++){
        for(; j<n; j++){
            if(2*v[i]<v[j])break;
            ans=min(ans, (ll)v.size()-(j-i+1));
        }
    }
    cout<<ans<<endl;
}