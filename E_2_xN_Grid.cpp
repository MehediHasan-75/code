#include<bits/stdc++.h>
using namespace std;
int main(){
    typedef long long ll;
    ll len, n, m;
    cin>>len>>n>>m;
    vector<pair<ll,ll>>vi(n), vj(m);
    for(auto &[x, y]:vi)cin>>x>>y;
    for(auto &[x, y]:vj)cin>>x>>y;
    ll ans=0, i=0, j=0;
    while(i<n and j<m){
        if(vi[i].second>vj[j].second){
            if(vi[i].first==vj[j].first){
                ans+=vj[j].second;
            }
            vi[i].second-=vj[j].second;
            j++;
        }
        else if(vi[i].second<vj[j].second){
            if(vi[i].first==vj[j].first){
                ans+=vi[i].second;
            }
            vj[j].second-=vi[i].second;
            i++;
        }
        else{
            if(vi[i].first==vj[j].first){
                ans+=vi[i].second;
            }
            i++;
            j++;
        }
    
    }
    cout<<ans<<endl;
}