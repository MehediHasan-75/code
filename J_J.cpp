#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>graph[25], val(25, 0);
vector<pair<ll,ll>>moves={{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
bool valid(ll x, ll y, ll row, ll col){
    return x<row and y<row and x>=0 and y>=0;
}
void build_graph(string s[], ll row, ll col){
    for(ll i=0; i<row; i++){
        for(ll j=0; j<col; j++){
            ll node= i*row + j;// representing each cell as a node of a graph.
            if(s[i][j]=='J'){//meet our necessery condition then set the value of node
                val[node]=1;
            }
            for(auto it:moves){
                ll new_i=i+it.first, new_j=j+it.second;

                if(valid(new_i, new_j, row, col)){//means cell is adjacent to node's cell
                    ll new_node=new_i*row+new_j;
                    graph[node].push_back(new_node);
                }
            }
        }
    }
}
map<ll,ll>mp;

ll func(ll mask, ll jersey){
    // cout<<jersey<<" ";
    ll total=__builtin_popcountll(mask);
    if(total==7){
        if(jersey>3){
            if(mp[mask]==0){
                mp[mask]=1;
                return 1;
            }
            return 0;
        }

        return 0;
    }
    ll ans=0;
    for(ll u=0; u<25; u++){
        if(mask&(1ll<<u)){
            for(auto v: graph[u]){
                if(mask&(1ll<<v))continue;
                ans+=func(mask|(1ll<<v), jersey+val[v]);
            }
        }
    }
    return ans;
}
int main(){
    string s[5];
    for(ll i=0; i<5; i++)cin>>s[i];
    build_graph(s, 5, 5);

    ll ans=0;
    for(ll i=0; i<25; i++){
        ans+= func((1ll<<i), val[i]);
    }
    cout<<ans<<"\n";
}