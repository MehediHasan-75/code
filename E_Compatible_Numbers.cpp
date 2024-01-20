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
ll Log=23, mxN=1<<Log;
vector<ll>ans1(mxN, -1), ans2(mxN, 0), ans3(mxN, 0);
int main(){
    fastio;
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(auto &it: v)cin>>it, ans1[it]=it;
    for(ll i=0; i<Log; i++){
        for(ll j=0; j<mxN; j++){
            if((j&(1<<i))){
                ans1[j]=max(ans1[j], ans1[j^(1<<i)]);
            }
        }
    }
    for(auto &it: v)cout<<ans1[(mxN-1)^it]<<" ";
    cout<<endl;

}