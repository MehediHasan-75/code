
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
void solve(ll tc)
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    map<char, vector<ll>>mp;
    for(ll i=0; i<n; i++){
        mp[s[i]].push_back((i%3));
    }
    if((n%3)==1)cout<<"YES\n";
    else if((n%3)==2){
        for(auto it: mp){
            ll ze=-1;
            for(auto idx:it.second){
                if(idx==1 and ze!=-1){
                    cout<<"YES\n";
                    return;
                }
                else if(idx==0) ze=1;
            }
        }
        cout<<"NO\n";
    }
    else{
        for(auto it: mp){
            ll ze=-1;
            for(auto idx:it.second){
                if(idx==2 and ze!=-1){
                    cout<<"YES\n";
                    return;
                }
                else if(idx==0) ze=1;
            }
        }
        cout<<"NO\n";
    }
    
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

