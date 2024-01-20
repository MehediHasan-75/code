
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
    //cout<<tc<<endl;
    ll n;
    cin>>n;
    vector<ll>pre(n-1);
    for(ll i=0; i<n-1; i++)cin>>pre[i];
    ll x=n*(n+1)/2;
    if(x!=pre.back()){
        pre.push_back(x);
        map<ll,ll>mp;
        mp[pre[0]]++;
        for(ll i=1; i<n; i++)mp[pre[i]-pre[i-1]]++;
        //for(auto &it: mp)cout<<it.first<<" "<<it.second<<endl;
        for(ll i=1; i<=n; i++){
            if(mp[i]==0 or mp[i]>1){
                cout<<"NO\n";
                return;
            }
            mp.erase(i);
        }
        if(mp.size()!=0)cout << "NO\n";
        else cout << "YES\n";
        return;
    }
    map<ll,ll>mp;
    mp[pre[0]]++;
    for(ll i=1; i<n-1; i++){
        mp[pre[i]-pre[i-1]]++;
    }
    // cout<<mp.size()<<endl;
    // for(auto &it: mp)cout<<it.first<<" "<<it.second<<endl;
    vector<ll>v;
    for(auto &it: mp){
        if(it.second>1)v.push_back(it.first);
    }
    if(v.size()>1){
        cout<<"NO\n";
        return;
    }
    if(v.size()==1){
        if(mp[v.back()]>2){
        cout<<"NO\n";
        return;
        }
    }
    ll cnt=0;
    for(ll i=1; i<=n; i++)if(mp[i]==0)cnt++;
    if(cnt!=2)cout << "NO\n";
    else cout << "YES\n";
    
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

