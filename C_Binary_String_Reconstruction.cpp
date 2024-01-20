#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    string  s;
    cin>>s;
    ll x, n=s.size();
    cin>>x;
    vector<char>ans(n, '1');
    // cout<<n<<endl;
    for(ll i=0; i<n; i++){
        // cout<<s[i]<<endl;
        if(s[i]=='0'){
            // cout<<'h'<<endl;
            if(i-x>=0){
                ans[i-x]='0';
                // cout<<ans[i-x]<<endl;
            }
            if(i+x<n){
                ans[i+x]='0';
            }
        }
    }
    // for(auto &it: ans)cout<<it;
    // cout<<endl;
    for(ll i=0; i<n; i++){
        if(s[i]=='0'){
            if(i-x>=0){
                if(ans[i-x]!='0'){
                    cout<<-1<<endl;
                    return;
                }
            }
            if(i+x<n){
                if(ans[i+x]!='0'){
                    cout<<-1<<endl;
                    return;
                }
            }
        }
        else{
            if(i-x>=0){
                if(ans[i-x]=='1'){
                    continue;
                }
            }
            if(i+x<n){
                if(ans[i+x]=='1'){
                    continue;
                }
            }
            cout<<-1<<endl;
            return;
        }
    }
    for(auto &it: ans)cout<<it;
    cout<<endl;
}
int main(){
    ll t;
    cin>>t;
    while(t--)solve();
}