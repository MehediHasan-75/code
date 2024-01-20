
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

vector<ll>v={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
void solve(ll tc)
{
    cout<<"Case "<<tc<<": ";
    map<ll,ll>mp;

    ll n;
    cin>>n;
    cout<<n<<" =";
    for(auto &num: v){
        ll n_=n;

        while(n_/num >0){
            mp[num]+=n_/num;
            n_/=num;
        }
    }
    auto it=mp.begin();
    cout<<" "<<it->first<<" "<<"("<<it->second<<")";
    it++;
    for(; it!=mp.end(); it++){
        cout<<" * "<<it->first<<" "<<"("<<it->second<<")";
    }
    cout<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

