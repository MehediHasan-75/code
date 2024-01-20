
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 2e5 + 10, inf=2e18;
ll mod = 1000000007;
map<char, ll>mp={{'A',1},{'B',10},{'C',100}, {'D',1000},{'E',10000}};
void solve(ll tc)
{
    string s;
    cin>>s;
    map<string,vector<ll>>mp1;
    vector<ll>v(s.size()+2,0);
    mp1["a"]=mp1["b"]=mp1["c"]=mp1["d"]=mp1["t"]=v;
    ll a=0,b=0,c=0, d=0, t=0;
    for(ll i=0; i<s.size(); i++){
        if(s[i]=='A')a+=1, t+=1;
        if(s[i]=='B')b+=10,t+=10;
        if(s[i]=='C')c+=100,t+=100;
        if(s[i]=='D')d+=1000,t+=1000;
        else t+=10000;
        mp1["a"][i]=a,mp1["b"][i]=b,mp1["c"][i]=c,mp1["d"][i]=d,mp1["t"][i]=t; 
    }
    ll mx=INT64_MIN, right=0;
    char mxc='\0';
    for(ll i=s.size()-1; i>=0; i--){
        ll temp_mx=right;
        
        if(s[i]>=mxc)right+=mp[s[i]];
        else right-=mp[s[i]];
        mxc=max((char)mx,(char)s[i]);
    }
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

