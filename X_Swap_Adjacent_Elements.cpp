#include<bits/stdc++.h>
using namespace std;
int main(){
    typedef long long ll;
    ll n;
    cin>>n;

    vector<ll>v(n);
    for(auto &it: v)cin>>it;
    string s;
    cin>>s;
    for(ll i=0; i<s.size(); i++){
        if(s[i]=='1'){
            ll j=i;
            while(j+1<n and s[j]=='1')j++;
            sort(v.begin()+i, v.begin()+j+1);
            // cout<<i<<" "<<j<<endl;
            i=j;
        }
    }
    // for(ll i=0; i<n; i++)cout<<v[i]<<" ";
    if(is_sorted(v.begin(), v.end()))cout << "YES\n";
    else cout << "NO\n";
}