#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    ll r, c, q;
    cin>>r>>c>>q;
    vector<vector<ll>>v(r, vector<ll>(c, 0));
    vector<vector<ll>>queries;

    for(ll i=0; i<q; i++){
        vector<ll>vv;
        ll t;
        cin>>t;
        vv.push_back(t);
        if(t==1){
            ll x;
            cin>>x;
            x--;
            vv.push_back(x);

        }
        else if(t==2){
            ll y;
            cin>>y;
            y--;
            vv.push_back(y);
        }
        else{
            ll x, y, val;
            cin>>x>>y>>val;
            x--, y--;
            vv.push_back(x);
            vv.push_back(y);
            vv.push_back(val);
        }
        queries.push_back(vv);
    }
    reverse(queries.begin(), queries.end());
    for(auto &it: queries){
        if(it.front()==1){
            ll x=it.back(), temp=v[x].back();
            for(ll i=v[x].size()-2; i>=0; i--){
                v[x][i+1]=v[x][i];
            }
            v[x].front()=temp;
        }
        else if(it.front()==2){
            ll y=it.back(), temp=v[r-1][y];
            for(ll i=r-2; i>=0; i--){
                v[i+1][y]=v[i][y];
            }
            v[0][y]=temp;
        }
        else if(it.front()==3){
            v[it[1]][it[2]]=it[3];
        }
    }
    for(ll i=0; i<r; i++){
        for(ll j=0; j<c; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}