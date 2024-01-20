
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
    ll n, k;
    cin>>n>>k;
    vector<ll>ans(n, 0);
    map<ll, queue<ll>>mp;
    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        if(mp[a].size()>=k)continue;
        else mp[a].push(i);
    }
    ll can=0;
    for(auto &it: mp)can+=it.second.size();
    ll cnt=(can/k)*k;
    //cout<<mp.size()/k<<endl;
    ll col=1;
    for(auto &it: mp){
        while(it.second.size()){
            ll ind=it.second.front();
            it.second.pop();
            cnt--;
            ans[ind]=col++;
            if(col>k)col=1;
            if(cnt==0)break;
        }
        if(cnt==0)break;
    }
    for(auto &it: ans)cout<<it<<" ";
    cout<<endl;
}
// k=0 to k;
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

