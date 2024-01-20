#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool ans(){
    ll n;
    cin>>n;

    string s, t;
    cin>>s>>t;

    string sac, tac;
    for(ll i=0; i<n; i++){
        if(s[i]=='a' or s[i]=='c')sac.push_back(s[i]);
        if(t[i]=='a' or t[i]=='c')tac.push_back(t[i]);
    }
    if(sac!=tac)return false;

    vector<ll>sa, ta, sc, tc;

    for(ll i=0; i<n; i++){
        if(s[i]=='a') sa.push_back(i);
        if(s[i]=='c') sc.push_back(i);
        if(t[i]=='a') ta.push_back(i);
        if(t[i]=='c') tc.push_back(i);
    }

    for(ll i=0; i<sa.size(); i++){
        if(sa[i]>ta[i])return false;
    }
    for(ll i=0; i<tc.size(); i++){
        if(tc[i]>sc[i])return false;
    }
    return true;
}
void solve(){
    if(ans())cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    ll t;
    cin>>t;
    while(t--)solve();
}