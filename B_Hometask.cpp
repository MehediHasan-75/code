#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n;
    cin>>n;
    ll on=-1, tw=-1, ze=0;
    map<ll,ll>mp;
    vector<ll>v1, v2;
    ll sm=0;
    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        sm+=a;
        mp[-a]++;
        if(a%3==1)v1.push_back(a);
        if(a%3==2)v2.push_back(a);
        if(a==0)ze=1;
    }
    //cout<<sm<<endl;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    if(ze!=1)cout<<-1<<endl;
    else{
        if(sm%3==1){
            if(v1.size())
            {
                on=v1[0];
                mp[-on]--;
                if(mp[-on]==0)mp.erase(-on);
            }
            else{
                if(v2.size()>1){
                   mp[-v2[0]]--;
                   mp[-v2[1]]--;
                   if(mp[-v2[0]]==0)mp.erase(-v2[0]);
                   if(v2[0]!=v2[1] and mp[-v2[1]]==0)mp.erase(-v2[1]);   
                }
                else cout<<-1<<endl;
            }
        }
        else if(sm%3==2){
            if(v2.size())tw=v2[0];
            if(tw==-1){
                if(v1.size()>1){
                    mp[-v1[0]]--;
                    mp[-v1[1]]--;
                    if(mp[-v1[0]]==0)mp.erase(-v1[0]);
                    if(v1[0]!=v1[1] and mp[-v1[1]]==0)mp.erase(-v1[1]);
                }
                else cout<<-1<<endl;
            }
            else{
                mp[-tw]--;
                if(mp[-tw]==0)mp.erase(-tw);
            }
        }
        if(mp.size()==1)cout<<0<<endl;
        else{
            for(auto &it: mp)
                while(it.second--)cout<<-it.first;
            cout<<endl;
        }
    }
}