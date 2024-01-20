#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n, m;
    cin>>n>>m;
    vector<pair<ll, ll>>v(m);
    for(ll i=0; i<m; i++)cin>>v[i].first>>v[i].second;
    // for(auto &it: v)cout<<it.first<<" "<<it.second<<endl;
    set<ll>ans;
    for(ll i=1; i<=100; i++){
        ll fl=1;
        for(ll j=0; j<m; j++){
            if((v[j].first+i-1)/i!= v[j].second){
                fl=0;
                break;
            }
        }
        // cout<<fl<<" ";
        if(fl){
          ans.insert((n+i-1)/i );
        }
    }
    // for(auto &it: ans)cout<<it<<" ";
    if(ans.size()!=1)cout<<-1<<endl;
    else{
        ll per=*ans.begin();
        cout<<per<<endl;
    }
}