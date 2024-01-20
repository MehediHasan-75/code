
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
    ll sum;
    cin>>sum;
    //cout<<sum<<endl;
    ll lo=0, hi=1e5;
    while(hi>=lo){
        ll mid=(hi+lo)>>1, n=mid;
        ll temp_sum=(n*(n+1))/2;
        //cout<<temp_sum<<" ";
        if(temp_sum==sum){
            cout<<mid<<endl;
            return;
        }
        if(temp_sum<sum)lo=mid+1;
        else hi=mid-1;
    }
    cout<<"NAI"<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

