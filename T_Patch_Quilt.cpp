#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s[50];
ll r, c;

vector<pair< pair<ll,ll>, string>>mv={{{0, 0}, "*, "},{{1, 0}, "D, "}, {{-1, 0}, "U, "}, {{0, -1}, "L, "}, {{0, 1}, "R, "}, {{-1, 1}, "UR, "}, {{1, -1}, "DL, "}, {{1, 1}, "DR, "}, {{-1, -1}, "UL, "}};

bool valid(ll x, ll y, ll ind, string &st){
    return (x<r and x>=0 and y<c and y>=0 and ind<st.size() and  st[ind]==s[x][y]);
}
ll cnt=0;
bool dfs(ll rr, ll cc, ll ind, string &st, string &ans){

    if(ind==st.size()){
        return true;
    }

    bool fl=false;
    for(auto it: mv){
        if(valid(rr+it.first.first, cc+it.first.second, ind, st)){
            // ans+=it.secon
            fl|=dfs(rr+it.first.first, cc+it.first.second, ind+1, st, ans);
        }
    }
    return fl;
}
void solve(ll tc){
    cout<<"Case "<<tc<<": \n";
    cin>>r>>c;

    for(ll i=0; i<r; i++)cin>>s[i];

    ll q;
    cin>>q;
    while(q--){
        string st;
        cin>>st;
        // cout<<st<<" ";
        bool fl=0;
        for(ll i=0; i<r; i++){
            if(fl)break;;
            for(ll j=0; j<c; j++){
                string ans="";
                // cout<<(s[i][j]==st.front())<<" ";
                if(s[i][j]==st.front()){
                    ans.clear();
                    if(dfs(i, j, 1, st, ans)){
                        ans.pop_back();
                        ans.pop_back();
                        cout<<st<<" found: ("<<i+1<<","<<j+1<<"), "<<ans<<endl;
                        fl=1;
                        break;
                    }
                }
            }
        }
        if(!fl){
            cout<<st<<" not found\n";
        }
        // cout<<endl;
    }
    for(ll i=0; i<r; i++)s[i].clear();
}
int main(){
    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++)solve(i);
}
