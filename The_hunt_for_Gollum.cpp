#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    typedef long long ll;

    ll n, m; cin>>n>>m;
    string t[n];
    for(ll i=0; i<n; i++)cin>>t[i];

    ll N, M; cin>>N>>M;
    string s[N];
    for(ll i=0; i<N; i++)cin>>s[i];

    vector<pair<ll,ll>>ans;

    for(ll i=0; i<N-n+1; i++){
        for(ll j=0; j<M-m+1; j++){
            bool fl=1;

            for(ll ii=0; ii<n; ii++){
                for(ll jj=0; jj<m; jj++){
                    if(s[i+ii][j+jj]!=t[ii][jj]){
                        fl=0;
                    }
                }
            }
            if(fl){
                    ans.push_back({i+1, j+1});
            }
        }
    }
    if(ans.size()){
        for(ll i=0; i<ans.size(); i++)
        cout<<"("<<ans[i].first<<","<<ans[i].second<<")\n";
    }
    else cout<<"NO MATCH FOUND...\n";
}